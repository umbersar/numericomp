#include<vector>

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NUMERICOMP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NUMERICOMP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NUMERICOMP_EXPORTS
#define NUMERICOMP_API __declspec(dllexport)
#else
#define NUMERICOMP_API __declspec(dllimport)
#endif

// This class is exported from the numericomp.dll
class NUMERICOMP_API Cnumericomp {
public:
	Cnumericomp(void);
	// TODO: add your methods here.
};

extern NUMERICOMP_API int nnumericomp;

NUMERICOMP_API int fnnumericomp(void);

#include"MatrixVec.h"
#include"MatrixDynMemoryNew.h"
#include"MatrixDynMemoryMalloc.h"
#include"MatrixDynMemoryAllocator.h"