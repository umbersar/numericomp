#pragma once

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
	
	//Using STL vector. 
	std::vector<T> data;
};

template<class T> Matrix<T> operator*(Matrix<T>& lhs, Matrix<T>& rhs) {
	if (lhs.Columns() != rhs.Rows()) {
		throw std::invalid_argument("The two matrices cannot be multiplied. Number of columns of LHS matrix should "
			"be equal to rows in RHS matrix");
	}

	Matrix<T> result(lhs.Rows(), rhs.Columns(), 0);

	for (int i = 0; i < lhs.Rows(); i++) {
		for (int j = 0; j < rhs.Columns(); j++) {
			for (int k = 0; k < rhs.Rows(); k++) {
				result(i, j) = result(i, j) + lhs(i, k) * rhs(k, j);
			}
		}
	}

	return result;
}