#include "Packet.h"
#include "crc.h"
#include "Log.h"


char PACKET_COMMAND::_Format[10240] = {0};

PACKET_COMMAND::PACKET_COMMAND()
{
	init();
}

PACKET_COMMAND::~PACKET_COMMAND()
{
}

void PACKET_COMMAND::init()
{
	memset((void*)data,0,PACKET_BUFFER_SIZE*sizeof(int8));
	SetNetID(0);
	_SetSize(0);
	_SetType(0);
	_cpos = 0;
	_rpos = _wpos = DATA_PARAM;
}

void PACKET_COMMAND::Copy(char * buf, uint16 size)
{
	if( size <= 0 || _cpos + size > PACKET_BUFFER_SIZE )
	{
		Log.Error("[Packet] Copy faild %s size=%d", toFormat(), size);
		return;
	}
	memcpy(data+_cpos, buf, size);
	_cpos += size;
}

bool PACKET_COMMAND::crcCheck()
{
	uint16 crc = Caluation_CRC16(_DataBuffer(), _DataSize());

	if (_CRC16() == crc ) return true;
	else Log.Error("[Packet] _CRC16():%d != crc:%d %s", _CRC16(), crc, toFormat());
	return false;
}

void PACKET_COMMAND::end(uint16 wType)
{
	_SetType(wType);
	_SetSize(_wpos);

	uint16 crc = Caluation_CRC16(_DataBuffer(), _DataSize());
	_SetCRC16(crc);
}

#if USE_SHARED_PARSER
void PACKET_COMMAND::put(int8 value)
{
	appendFlag(BYTE_FLAG);
	append(value);
}

void PACKET_COMMAND::put(uint16 value)
{
	appendFlag(WORD_FLAG);
	append(value);
}

void PACKET_COMMAND::put(int value)
{
	appendFlag(INT_FLAG);
	append(value);
}

void PACKET_COMMAND::put(int64 value)
{
	appendFlag(INT64_FLAG);
	append(value);
}

void PACKET_COMMAND::put(const char * value, uint16 size)
{
	appendFlag(STRING_FLAG);
	append(size);
	append(value, size);
}

void PACKET_COMMAND::get(int8 & value)
{
	if( checkFlag(BYTE_FLAG) )
		read(value);
}

void PACKET_COMMAND::get(uint16 & value)
{
	if( checkFlag(WORD_FLAG) )
		read(value);
}

void PACKET_COMMAND::get(int & value)
{
	if( checkFlag(INT_FLAG) )
		read(value);
}

void PACKET_COMMAND::get(int64 & value)
{
	if( checkFlag(INT64_FLAG) )
		read(value);
}

void PACKET_COMMAND::get(char * value, uint16 size)
{
	if( !checkFlag(STRING_FLAG) )
		return;
	
	uint16 svalue = 0;
	read(svalue);

	int s = svalue < size ? svalue : size;

	read(value, s);
}

template<typename T> void PACKET_COMMAND::append(T value) 
{
	_append((char *)&value, sizeof(value));
}

template<typename T> void PACKET_COMMAND::read(T & value) 
{
	_read((char *)&value, sizeof(value));
}

inline void PACKET_COMMAND::append(const char * value, uint16 size) 
{
	_append(value, size);
}

inline void PACKET_COMMAND::read(char * value, int size)
{
	_read(value, size);
}

inline void PACKET_COMMAND::_append(const char * value, uint16 size)
{
	assert( _wpos + size <= PACKET_BUFFER_SIZE - DATA_PARAM );
	if( _wpos + size <= PACKET_BUFFER_SIZE - DATA_PARAM )
	{
		memcpy(&data[_wpos], value, size);
		_wpos += size;
	}
}

inline void PACKET_COMMAND::_read(void * value, int size)
{
	assert( _rpos + size <= (int)PACKET_BUFFER_SIZE - DATA_PARAM );
	if( _rpos + size <= (int)PACKET_BUFFER_SIZE - DATA_PARAM )
	{
		memcpy(value, &data[_rpos], size);
		_rpos += size;
	}
}

inline void PACKET_COMMAND::appendFlag(int8 flag)
{
	data[_wpos] = flag;
	_wpos += sizeof(int8);
}

inline bool PACKET_COMMAND::checkFlag(int8 flag)
{
	int8 value = 0;
	read(value);
	return value == flag;
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#if USE_PROTOCOL_BUFFER
void PACKET_COMMAND::setBuffer(uint16 wType, const char* buf, uint16 size)
{
	//assert( _wpos + size <= PACKET_BUFFER_SIZE );
	if( _wpos + size <= PACKET_BUFFER_SIZE )
	{
		memcpy(&data[DATA_PARAM], buf, size);
		_wpos += size;
		end(wType);
	}
	else
	{
		Log.Error("[Packet] setBuffer failed, type:%d _wpos:%d size:%d", wType, _wpos, size);
	}
}

void PACKET_COMMAND::getBuffer(std::string& buf)
{
	//assert( Size() >= _rpos );
	if( Size() >= _rpos )
	{
		buf.assign((char*)&data[_rpos], _DataSize());
		//_rpos += _DataSize();
	}
	else
	{
		Log.Error("[Packet] getBuffer failed, _rpos:%d size:%d", _rpos, Size());
	}
}
#endif
