/*
 * base64加密
 *
 *				songjun 2012.12.27
 */


#ifndef SHARED_BASE64_H
#define SHARED_BASE64_H


int DecodeBase64(const char* pSrc, char* pDst, int nSrcLen);
int EncodeBase64(const char* pSrc, char* pDst, int nSrcLen/*, int nMaxLineLen*/);


#endif	//SHARED_BASE64_H
