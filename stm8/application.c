#include "adc.h"
#include "nvdata.h"
#include "si7021.h"
#include "bh1750.h"
#include "si4432.h"
#include "application.h"

#define CLIENT
//#define SERVER

#define ACK_COUNT      2
#define ACK_TIMEOUT    100
#define KICK_TIMEOUT   (180 * 0.59375)
#define SENSOR_TIMEOUT (60000.0 * 0.59375)

static void PrintUInt16( char const *Name, uint16_t Value );
static void LowPowerHalt( void );
static void SetLowPowerTimer( uint16_t const Interval );
static void SendAckToClient( void );
static void SendSensorData();

static uint8_t Rssi;
static uint8_t AckCount;
static uint8_t AckTimer;
static int16_t Temperature;
static uint16_t Voltage;
static uint16_t Humidity;
static uint16_t Illuminance;
static enum EState State;
static union TData Data;

void AppInit( void )
{
  bool Res;

  puts( "Sally proto board" );
  HMI_BUZZER( 10 );
  HAL_MsDelay( 100 );
  HMI_BUZZER( 10 );
  HAL_MsDelay( 100 );
  HMI_BUZZER( 10 );

  NvDataInit();
  AdcInit();
  I2cInit();
  SpiInit();

PrintUInt16( "MyAddr: ", NvData.MyAddr );
PrintUInt16( "GwAddr: ", NvData.GwAddr );
PrintUInt16( "RfOsc: ", NvData.RfOsc );
PrintUInt16( "RfPower: ", NvData.RfPower );
PrintUInt16( "RfChannel: ", NvData.RfChannel );

  Res = Si4432Init();
  if( Res == false )
  {
    HMI_ERROR_ON();
    puts( "SI4432 not detected" );
  }

#if defined( CLIENT )
  State = StateTxStart;
#elif defined( SERVER )
  State = StateRxStart;
#else
#error "CLIENT or SERVER should be defined"
#endif
}

void AppLoop( void )
{
  uint8_t Len;

  switch( State )
  {
    case StateNull:
      State = StateNull;
      break;

    case StateTxStart:
      HMI_LED_ON();

      SetLowPowerTimer( KICK_TIMEOUT );
      State = StateTxKickWait;
      LowPowerHalt();
      break;

    case StateTxKickWait:
      break;

    case StateTxKickDone:
      AckCount = ACK_COUNT;
      HMI_LED_OFF();
      SetLowPowerTimer( SENSOR_TIMEOUT );

      Voltage = AdcGetVoltage();

#if 1
      PrintUInt16( "R ", Rssi );
      PrintUInt16( "V ", Voltage );
      PrintUInt16( "T ", Temperature );
      PrintUInt16( "H ", Humidity );
      PrintUInt16( "I ", Illuminance );
#endif

      State = StateTxWait;
      SendSensorData();
      break;

    case StateTxWait:
      break;

    case StateTxDone:
#if 1
      puts( "tx done" );
      Si4432Standby();
      State = StateNull;
      LowPowerHalt();
#else
      AckTimer = ACK_TIMEOUT;
      State = StateTxAckWait;
      Si4432Receive();
#endif
      break;

    case StateTxAckWait:
      break;

    case StateTxAckDone:
      puts( "tx done" );
      AckCount = 0; // Stop ack timer
      Len = Si4432ReadRxPacket( Data.Buffer, sizeof( Data ));
      Si4432Standby();
      State = StateNull;
      LowPowerHalt();
      break;

    case StateTxAckTimeout:
      HMI_BUZZER( 1 );
      if( AckCount )
      {
        puts( "AckTimeout - retry" );
        AckCount--;
        State = StateTxWait;
        SendSensorData();
      }
      else
      {
        puts( "AckTimeout" );
        Si4432Standby();
        State = StateNull;
        LowPowerHalt();
      }
      break;

    case StateRxStart:
      State = StateRxWait;
      Si4432Receive();
      LowPowerHalt();
      break;

    case StateRxWait:
      break;

    case StateRxDone:
      Len = Si4432ReadRxPacket( Data.Buffer, sizeof( Data ));
      if( Data.Header.RxAddr == NvData.GwAddr )
      {
        State = StateRxAckWait;
        SendAckToClient();
      }
      else
      {
        State = StateRxStart;
      }
      break;

    case StateRxAckWait:
      break;

    case StateRxAckDone:
      puts( "rx done" );
      State = StateRxStart;
      break;

    default:
      State = StateNull;
      break;
  }
}

void AppInterruptRTC( void )
{
  if( State == StateNull )
  {
    State = StateTxStart;
  }
  else if( State == StateTxKickWait )
  {
    State = StateTxKickDone;
  }
}

void AppInterruptSysTick( void )
{
  if( AckTimer )
  {
    AckTimer--;
    if( AckTimer == 0 )
    {
      State = StateTxAckTimeout;
    }
  }
}

void AppInterruptTransmit( void )
{
  if( State == StateTxWait )
  {
    State = StateTxDone;
  }
  else if( State == StateRxAckWait )
  {
    State = StateRxAckDone;
  }
}

void AppInterruptReceive( void )
{
  if( State == StateRxWait )
  {
    State = StateRxDone;
  }
  else if( State == StateTxAckWait )
  {
    State = StateTxAckDone;
  }
}

void AppInterruptSyncWord( void )
{
  Rssi = Si4432ReadRssi();
}

static void PrintUInt16( char const *Name, uint16_t Value )
{
  char *Ptr;
  char Text[ 8 ];

  while( *Name )
  {
    putchar( *Name++ );
  }

  Ptr = &Text[ 7 ];
  *Ptr = '\0';
  do
  {
    *--Ptr = '0' + ( Value % 10 );
    Value /= 10;
  }
  while( Value );
  puts( Ptr );
}

static void LowPowerHalt( void )
{
  PWR_UltraLowPowerCmd( ENABLE );
  halt();
}

static void SetLowPowerTimer( uint16_t const Interval )
{
  RTC_WakeUpCmd( DISABLE );
  RTC_SetWakeUpCounter( Interval );
  RTC_WakeUpCmd( ENABLE );
}

// Send acknovledge back to client
// Received message in Data
static void SendAckToClient( void )
{
#if 0
  struct TAck Ack;

  PrintUInt16( "R ", Data.Sensor.Rssi );
  PrintUInt16( "V ", Data.Sensor.Voltage );
  PrintUInt16( "T ", Data.Sensor.Temperature );
  PrintUInt16( "H ", Data.Sensor.Humidity );
  PrintUInt16( "I ", Data.Sensor.Illuminance );

  Ack.Header.Length = sizeof( struct TAck );
  Ack.Header.RxAddr = Data.Header.TxAddr;
  Ack.Header.TxAddr = Data.Header.RxAddr;
  Ack.Header.MsgId = MsgIdAck;
  Ack.Header.Flag = 0;
  Ack.Header.Spare = 0;

  Si4432Transmit( (uint8_t*)&Ack, sizeof( Ack ));
#endif
}

static void CopySwap16( void *Dest_, void *Source_ )
{
  uint8_t *Dest = Dest_;
  uint8_t *Source = Source_;
  Dest[0] = Source[1];
  Dest[1] = Source[0];
}


static void SendSensorData( void )
{
  struct TSensor Sensor;

  memset( &Sensor, 0, sizeof( Sensor ));
  Sensor.Header.RxAddr = NvData.MyAddr;
  Sensor.Header.TxAddr = NvData.GwAddr;
  Sensor.Header.MsgId  = 10;
  Sensor.Header.Flag   = 0;

  CopySwap16( &Sensor.Voltage, &Voltage );
  CopySwap16( &Sensor.Humidity, &Humidity );
  CopySwap16( &Sensor.Illuminance, &Illuminance );
  CopySwap16( &Sensor.Temperature, &Temperature );

  Si4432Transmit( (uint8_t*)&Sensor, sizeof( Sensor ));
}


