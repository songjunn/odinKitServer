#include "crc.h"
#include "Log.h"

unsigned short Caluation_CRC16(char * buff, int size)
{
	unsigned short crctemp, crc = 0xffff;
	unsigned short i,j;
	for( i=0; i<size; ++i )
	{
		crc ^= buff[i];
		for( j=0; j<8; ++j )
		{
			crctemp = crc;
			crc >>= 1;
			if( crctemp & 0x0001 )
				crc ^= 0xa001;
		}
	}
	return crc;
}
