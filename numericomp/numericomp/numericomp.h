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

//template class not marked by NUMERICOMP_API but still works
template<class T>
class Matrix
{
public:
	Matrix(const size_t& rows, const size_t& columns)
		:nRows(rows), nColumns(columns), data(rows*columns, NAN)
	{

	}

	Matrix(const size_t& rows, const size_t& columns, const T& initValue)
		:nRows(rows), nColumns(columns), data(rows*columns, initValue)
	{

	}


	~Matrix() {

	}

	//transpose,multiply ,+,- operator
	int Rows()const {
		return nRows;
	}

	int Columns()const {
		return nColumns;
	}

	T operator()(int row, int column) const {
		if (row >= nRows || column >= nColumns)
			throw std::out_of_range("Matrix subscript out of bounds");

		return data[row*nColumns + column];
	}

	T& operator()(int row, int column) {
		if (row >= nRows || column >= nColumns)
			throw std::out_of_range("Matrix subscript out of bounds");

		return data[row*nColumns + column];
	}

private:
	size_t nRows;
	size_t nColumns;

	//using new causes initialization of memory(in this case to 0). so would have to use somethig else. Should I use STL allocator class to do memory
	//allocations. malloc in c did not inititialize memory.
	std::vector<T> data;
};

template<class T> Matrix<T> operator*(Matrix<T>& lhs, Matrix<T>& rhs) {
	if (lhs.nColumns != rhs.nRows) {
		throw std::invalid_argument("The two matrices cannot be multiplied. Number of columns of LHS matrix should "
			"be equal to rows in RHS matrix");
	}

	Matrix<T> result(lhs.nRows, rhs.nColumns, 0);

	for (int i = 0; c < lhs.nRows; c++) {
		for (int j = 0; d < rhs.nColumns; d++) {
			for (int k = 0; k < rhs.nRows; k++) {
				result[i][j] = result[i][j] + first[i][k] * second[k][j];
			}
		}
	}

	return result;
}