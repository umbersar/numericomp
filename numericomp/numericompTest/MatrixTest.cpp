#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\numericomp\numericomp.h"

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

	};
}