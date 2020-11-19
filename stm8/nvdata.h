#ifndef NVDATA_H__
#define NVDATA_H__

#include "iodef.h"


typedef struct
{
  uint8_t Checksum;
  uint8_t Schema;
  uint8_t MyAddr;
  uint8_t GwAddr;
  uint8_t RfOsc;
  uint8_t RfPower;
  uint8_t RfChannel;
} TNvData;
#define NvData (*(TNvData*)FLASH_DATA_START_PHYSICAL_ADDRESS)

void NvDataInit( void );
void NvDataLock( void );
void NvDataUnlock( void );
void NvDataErase( void );
void NvDataUpdateChecksum( void );
bool NvDataCheckChecksum( void );

#endif // NVDATA_H__


