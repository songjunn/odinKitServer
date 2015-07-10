#ifndef	SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <string>
#include "platform.h"

#define _RELOADNEW_		//reload new and delete
#define _NEDMALLOC_		//use nedmalloc memory pool

// ---------------------------------------------------------------------------------- //
// Memory allocation.
// ---------------------------------------------------------------------------------- //

// Use these to allocate and free memory.
void*		Debug_Alloc( unsigned long size, const char * szFile, int nLine );				// Allocate some memory.
void*		Debug_Realloc( void *ptr, unsigned long size, const char * szFile, int nLine );	// Rellocate some memory. It may or may not return the same
void		Debug_Free( void *ptr, const char * szFile, int nLine );						// Free some memory.

// Use these to allocate and free memory.
void*		Release_Alloc( unsigned long size );											// Allocate some memory.
void*		Release_Realloc( void *ptr, unsigned long size );								// Rellocate some memory. It may or may not return the same
void		Release_Free( void *ptr );														// Free some memory.

// Use this to hook allocation errors.
void		AllocErrorHandler( unsigned long size, const char * szFile = 0, int nLine = 0 );

#ifdef _DEBUG
#define		MemAlloc( size )		Debug_Alloc( size, __FILE__, __LINE__ )			// Allocate some memory.
#define		MemRealloc( ptr, size )	Debug_Realloc( ptr, size, __FILE__, __LINE__ )	// Rellocate some memory. It may or may not return the same
#define		MemFree( ptr )			Debug_Free( ptr, __FILE__, __LINE__ )			// Free some memory.
#else
#define		MemAlloc( size )		Release_Alloc( size )							// Allocate some memory.
#define		MemRealloc( ptr, size )	Release_Realloc( ptr, size )					// Rellocate some memory. It may or may not return the same
#define		MemFree( ptr )			Release_Free( ptr )								// Free some memory.
#endif

#ifdef _DEBUG
#define		NEW					new(__FILE__, __LINE__)
#define SAFE_DELETE(p)			if(p){operator delete ((p), __FILE__, __LINE__);(p)=NULL;}
#define SAFE_DELETE_ARRAY(p)	if(p){operator delete [] ((p), __FILE__, __LINE__);(p)=NULL;}
#else
#define	NEW						new
#define SAFE_DELETE(p)			if(p){operator delete (p);(p)=NULL;}
#define SAFE_DELETE_ARRAY(p)	if(p){operator delete [] (p);(p)=NULL;}
#endif


#ifdef _RELOADNEW_
void * operator new(size_t size) throw (std::bad_alloc);
void operator delete(void* ptr) throw ();
#endif

void * operator new[](size_t size) throw (std::bad_alloc);
void operator delete[](void* ptr) throw ();

void * operator new(size_t size, const char* file, const size_t line) throw ();
void operator delete(void * ptr, const char* file, const size_t line) throw (); 

void * operator new[](size_t size, const char* file, const size_t line) throw ();
void operator delete[](void * ptr, const char* file, const size_t line) throw ();


#endif	//SHARED_MEMORY_H
