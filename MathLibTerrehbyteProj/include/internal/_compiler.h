//////////////////////////////////////////////////////////////////////////
//	File:	_compiler.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Wraps up declspec into a macro for neatness and reduce duplication
//
//////////////////////////////////////////////////////////////////////////

#ifndef _COMPILER_H_
#define _COMPILER_H_

#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
	#define _WIN32
#endif

#ifdef _WIN32
	#ifdef TBYTEMATH_EXPORT
		#define TBYTELIB __declspec(dllexport)
	#elif defined(TBYTEMATH_IMPORT) 
		#define TBYTELIB __declspec(dllimport)
	#else
		#define TBYTELIB
	#endif
#endif

#endif