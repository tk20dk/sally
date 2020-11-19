#ifndef APP_H__
#define APP_H__

#include "iodef.h"

enum EState
{
  StateNull,
  StateTxStart,
  StateTxKickWait,
  StateTxKickDone,
  StateTxWait,
  StateTxDone,
  StateTxAckWait,
  StateTxAckDone,
  StateTxAckTimeout,
  StateRxStart,
  StateRxWait,
  StateRxDone,
  StateRxAckWait,
  StateRxAckDone
};

enum EMsgId
{
  MsgIdNull,
  MsgIdAck,
  MsgIdSensor,
  MsgIdConfig
};

struct THeader
{
  uint8_t TxAddr; // Destination address
  uint8_t RxAddr; // Source address
  uint8_t MsgId;  // Message identifier
  uint8_t Flag;
};

struct TAck
{
  struct THeader Header;
};

struct TSensor
{
  struct THeader Header;
  int16_t  Temperature;
  int16_t  TemperatureEx[ 8 ];
  uint16_t Flag;
  uint16_t Voltage;
  uint16_t Pressure;
  uint16_t Humidity;
  uint16_t Illuminance;
};

struct TConfig
{
  struct THeader Header;
  uint8_t Power;
  uint8_t DataRate;
};

union TData
{
  uint8_t Buffer[ 32 ];
  struct TAck Ack;
  struct TConfig Config;
  struct TSensor Sensor;
  struct THeader Header;
};

extern void AppInit( void );
extern void AppLoop( void );
extern void AppInterruptRTC( void );
extern void AppInterruptReceive( void );
extern void AppInterruptTransmit( void );
extern void AppInterruptSysTick( void );

#endif // APP_H__

