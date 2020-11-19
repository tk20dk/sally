#include "nvdata.h"
#include <stdio.h>


void NvDataInit( void )
{
  bool const Valid = NvDataCheckChecksum();

  if(( Valid == false ) || ( NvData.Schema != NV_SCHEMA ))
  {
    puts( "NvData error!" );

    NvDataUnlock();
    NvDataErase();

    NvData.Schema    = NV_SCHEMA;
    NvData.MyAddr    = NV_MY_ADDR;
    NvData.GwAddr    = NV_GW_ADDR;
    NvData.RfOsc     = NV_RF_OSC;
    NvData.RfPower   = NV_RF_POWER;
    NvData.RfChannel = NV_RF_CHANNEL;
    NvDataUpdateChecksum();
    NvDataLock();
  }
}

void NvDataLock( void )
{
  FLASH_Lock( FLASH_MemType_Data );
}

void NvDataUnlock( void )
{
  FLASH_Unlock( FLASH_MemType_Data );
}

void NvDataErase( void )
{
  uint8_t *const Data = (uint8_t*)&NvData;
  uint8_t Index;

  for( Index = 0; Index < sizeof( TNvData ); Index++ )
  {
    Data[ Index ] = 0;
  }
}

void NvDataUpdateChecksum( void )
{
  uint8_t Sum = 0;
  uint8_t const *const Data = (uint8_t const*)&NvData;
  uint8_t Index;

  for( Index = 0; Index < sizeof( TNvData ); Index++ )
  {
    Sum += Data[ Index ];
  }
  NvData.Checksum = -Sum;
}

bool NvDataCheckChecksum( void )
{
  uint8_t Sum = 0;
  uint8_t const *const Data = (uint8_t const*)&NvData;
  uint8_t Index;

  for( Index = 0; Index < sizeof( TNvData ); Index++ )
  {
    Sum += Data[ Index ];
  }
  return Sum ? false : true;
}

