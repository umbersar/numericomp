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

			Matrix<double> mat(matrixRows, matrixColumns);

			for (int i = 0; i < matrixRows; i++)
				for (int j = 0; j < matrixColumns; j++)
					Assert::IsTrue(isnan(mat(i, j)));
		}

	};
}