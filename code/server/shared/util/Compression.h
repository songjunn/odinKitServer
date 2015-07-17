#ifndef SHARED_ZIP_H
#define SHARED_ZIP_H

#include "SharedInc.h"
#include "zlib.h"


ULONG ComputeComSize(ULONG inSize);

bool ZipBufferToBuffer(uint8 * outBufeer, ULONG & uOutLen, uint8 * inBuffer, ULONG uInLen, int iCompressLevel = Z_DEFLATED);

bool UnZipBufferToBuffer(uint8 * outBufeer, ULONG & uOutLen, uint8 * inBuffer, ULONG uInLen);


#endif	//SHARED_ZIP_H