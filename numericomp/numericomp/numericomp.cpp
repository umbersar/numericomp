// numericomp.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"



// This is an example of an exported variable
NUMERICOMP_API int nnumericomp=0;

// This is an example of an exported function.
NUMERICOMP_API int fnnumericomp(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see numericomp.h for the class definition
Cnumericomp::Cnumericomp()
{
    return;
}
