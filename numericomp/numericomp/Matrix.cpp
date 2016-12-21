#include "stdafx.h"

Matrix::Matrix(const size_t& rows, const size_t& columns)
	:nRows(rows), nColumns(columns), data(rows*columns,NAN)
{
	
}

Matrix::~Matrix()
{
}

double Matrix::operator()(int row, int column) const {
	if (row >= nRows || column >= nColumns)
		throw std::out_of_range("Matrix subscript out of bounds");

	return data[row*nColumns + column];
}

double& Matrix::operator()(int row, int column) {
	if (row >= nRows || column >= nColumns)
		throw std::out_of_range("Matrix subscript out of bounds");

	return data[row*nColumns + column];
}

int Matrix::Rows()const {
	return nRows;
}

int Matrix::Columns()const {
	return nColumns;
}