#ifndef SI4432_H__
#define SI4432_H__

#include "spi.h"


#define INT1_CRC_ERROR        0x01U // CRC error in received packet
#define INT1_PACKET_RECEIVED  0x02U // Packet received interrupt
#define INT1_PACKET_SENT      0x04U // Packet sent interrupt
#define INT2_POWER_ON_RESET   0x01U // Power On Reset
#define INT2_CHIP_READY       0x02U // Chip Ready
#define INT2_WAKEUP_TIMER     0x08U // Wake-up Timer
#define INT2_RSSI_LEVEL       0x10U // RSSI Level
#define INT2_INVALID_PREAMBLE 0x20U // Invalid Preamble
#define INT2_VALID_PREAMBLE   0x40U // Valid Preamble
#define INT2_SYNC_WORD        0x80U // Sync Word

// http://www.airspayce.com/mikem/arduino/RadioHead/RH__RF22_8h_source.html
  
enum EDataRate
{
  DataRate256k,
  DataRate128k,
  DataRate64k,
  DataRate32k,
  DataRate16k,
  DataRate8k,
  DataRate4k,
  DataRate2k,
  DataRate1k,
  DataRate500,
  DataRate250,
  DataRate123
};

struct TStatus
{
  uint8_t Mode1;
  uint8_t Mode2;
  uint8_t DevStatus;
  uint8_t IntStatus1;
  uint8_t IntStatus2;
  uint8_t IntEnable1;
  uint8_t IntEnable2;
  uint8_t Spare[ 1 ];
};


#define Si4432SetOscLoad( OscLoad ) WriteRegister( 0x09, OscLoad )
#define Si4432GetOscLoad() ReadRegister( 0x09 )
#define Si4432SetTxPower( TxPower ) WriteRegister( 0x6d, TxPower )


void Si4432Interrupt( void );

bool Si4432Init( void );
void Si4432SetMode( uint8_t const Mode );
void Si4432Idle( void );
void Si4432Standby( void );
void Si4432Receive( void );
void Si4432ClearRxFifo( void );
void Si4432ClearTxFifo( void );
void Si4432Transmit( uint8_t const *const Buffer, uint8_t const Length );
void Si4432SetChannel( uint8_t const Channel );
void Si4432SetDataRate( enum EDataRate const Data_Rate );
void Si4432ReadStatus( struct TStatus *Status );

void Si4432SetWakeUpTimer( uint32_t const Interval );
void WriteRegister( uint8_t const Register, uint8_t const Data );

uint8_t Si4432ReadRssi( void );
uint8_t Si4432GetChannel( void );
uint8_t Si4432ReadRxPacket( uint8_t *Buffer, uint8_t const MaxLen );
uint16_t Si4432GetVoltage( void );
int16_t Si4432GetTemperature( void );

#endif // SI4432_H__


