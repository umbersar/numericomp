#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\numericomp\numericomp.h"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace numericompTest
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(InitMatrix)
		{
			int matrixRows = 4;
			int	matrixColumns = 4;

			Matrix<double> mat1(matrixRows, matrixColumns);

			for (int i = 0; i < matrixRows; i++)
				for (int j = 0; j < matrixColumns; j++)
					Assert::IsTrue(isnan(mat1(i, j)));

			Matrix<double> mat2(matrixRows, matrixColumns, 0);

			for (int i = 0; i < matrixRows; i++)
				for (int j = 0; j < matrixColumns; j++)
					Assert::AreEqual(mat2(i, j), 0.0, L"Not equal");
		}

		TEST_METHOD(MultMatrix)
		{
			int matrix1Rows = 3;
			int	matrix1Columns = 2;

			int matrix2Rows = 2;
			int	matrix2Columns = 3;

			int matrix3Rows = 3;
			int	matrix3Columns = 3;

			Matrix<double> mat1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					mat1(i, j) = i*matrix1Columns + j + 1;

			Matrix<double> mat2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					mat2(i, j) = i*matrix2Columns + j + 1;

			Matrix<double> mat3(matrix3Rows, matrix3Columns, 0);

			mat3 = mat1 * mat2;

			static const double resultsArr[] = { 9,12,15,19,26,33,29,40,51 };

			for (int i = 0; i < matrix3Rows; i++)
				for (int j = 0; j < matrix3Columns; j++)
					Assert::AreEqual(mat3(i, j), resultsArr[i*matrix2Columns + j]);

		}

	};
}