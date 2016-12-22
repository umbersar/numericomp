#pragma once

//template class not marked by NUMERICOMP_API but still works
template<class T>
class MatrixDynMemoryMalloc
{
public:
	MatrixDynMemoryMalloc(const size_t& rows, const size_t& columns)
		:nRows(rows), nColumns(columns)
	{
		data = (double*)malloc(rows * columns * sizeof(T));
	}

	MatrixDynMemoryMalloc(const size_t& rows, const size_t& columns, const T& initValue)
		:nRows(rows), nColumns(columns)
	{
		data = (double*)malloc(rows * columns * sizeof(T));

		for (size_t i = 0; i < nRows; i++) {
			for (size_t j = 0; j < nColumns; j++)
			{
				data[i*nColumns + j] = initValue;
			}
		}
	}

	// Copy constructor
	MatrixDynMemoryMalloc(const MatrixDynMemoryMalloc &m)
		:nRows(m.Rows()), nColumns(m.Columns())
	{
		data = (double*)malloc(m.Rows() * m.Columns() * sizeof(T));

		for (size_t i = 0; i < nRows; i++) {
			for (size_t j = 0; j < nColumns; j++)
			{
				data[i*nColumns + j] = m(i, j);
			}
		}
	}

	// Assignment operator
	MatrixDynMemoryMalloc& operator=(const MatrixDynMemoryMalloc &m) {
		if (this != &m) {
			Dispose();

			data = (double*)malloc(m.Rows() * m.Columns() * sizeof(T));

			for (size_t i = 0; i < nRows; i++) {
				for (size_t j = 0; j < nColumns; j++)
				{
					data[i*nColumns + j] = m(i, j);
				}
			}
		}
		return *this;
	}

	~MatrixDynMemoryMalloc() {
		Dispose();
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

	//using new causes initialization of memory by calling default constructor in case T is a class type(for double or int it wont initialize the memory to 0 and that is what i want).
	T *data;

	void Dispose() {
		free(data);
	}
};

template<class T> MatrixDynMemoryMalloc<T> operator*(MatrixDynMemoryMalloc<T>& lhs, MatrixDynMemoryMalloc<T>& rhs) {
	if (lhs.Columns() != rhs.Rows()) {
		throw std::invalid_argument("The two matrices cannot be multiplied. Number of columns of LHS matrix should "
			"be equal to rows in RHS matrix");
	}

	MatrixDynMemoryMalloc<T> result(lhs.Rows(), rhs.Columns(), 0);

	for (int i = 0; i < lhs.Rows(); i++) {
		for (int j = 0; j < rhs.Columns(); j++) {
			for (int k = 0; k < rhs.Rows(); k++) {
				result(i, j) = result(i, j) + lhs(i, k) * rhs(k, j);
			}
		}
	}

	return result;
}