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

template<class T>
class NUMERICOMP_API Matrix
{
public:
	Matrix(const size_t& rows, const size_t& columns);
	~Matrix();

	//transpose,multiply ,+,- operator
	int Rows()const;
	int Columns()const;

	T operator()(int row, int column) const;
	T& operator()(int row, int column);

private:
	size_t nRows;
	size_t nColumns;

	//using new causes initialization of memory(in this case to 0). so would have to use somethig else. Should I use STL allocator class to do memory
	//allocations. malloc in c did not inititialize memory.
	std::vector<T> data;

};