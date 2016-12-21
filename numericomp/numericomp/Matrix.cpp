#include "stdafx.h"

template<class T> Matrix<T>::Matrix(const size_t& rows, const size_t& columns)
	:nRows(rows), nColumns(columns), data(rows*columns,NAN)
{
	
}

template<class T> Matrix<T>::~Matrix()
{
}

template<class T> T Matrix<T>::operator()(int row, int column) const {
	if (row >= nRows || col >= nColumns)
		throw std::out_of_range("Matrix subscript out of bounds");

	return data[row*nColumns + column];
}

template<class T> T& Matrix<T>::operator()(int row, int column) {
	if (row >= nRows || col >= nColumns)
		throw std::out_of_range("Matrix subscript out of bounds");

	return data[row*nColumns + column];
}

template<class T> int Matrix<T>::Rows()const {
	return nRows;
}

template<class T> int Matrix<T>::Columns()const {
	return nColumns;
}