#include "stdafx.h"
#include "CppUnitTest.h"

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

		
		TEST_METHOD(MultDynNewMatrix)
		{
			int matrix1Rows = 3;
			int	matrix1Columns = 2;

			int matrix2Rows = 2;
			int	matrix2Columns = 3;

			int matrix3Rows = 3;
			int	matrix3Columns = 3;

			MatrixDynMemoryNew<double> mat1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					mat1(i, j) = i*matrix1Columns + j + 1;

			MatrixDynMemoryNew<double> mat2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					mat2(i, j) = i*matrix2Columns + j + 1;

			MatrixDynMemoryNew<double> mat3(matrix3Rows, matrix3Columns);

			boost::timer::cpu_timer timer;
			timer.stop();

			timer.start();
			mat3 = mat1 * mat2;
			timer.stop();

			boost::timer::cpu_times timesNaive = timer.elapsed();
			printf("Timings for matrix  multiplication using my vector is %s\n", timer.format().c_str());


			static const double resultsArr[] = { 9,12,15,19,26,33,29,40,51 };

			for (int i = 0; i < matrix3Rows; i++)
				for (int j = 0; j < matrix3Columns; j++)
					Assert::AreEqual(mat3(i, j), resultsArr[i*matrix2Columns + j]);

		}
		
		TEST_METHOD(MultDynMallocMatrix)
		{
			int matrix1Rows = 3;
			int	matrix1Columns = 2;

			int matrix2Rows = 2;
			int	matrix2Columns = 3;

			int matrix3Rows = 3;
			int	matrix3Columns = 3;

			MatrixDynMemoryMalloc<double> mat1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					mat1(i, j) = i*matrix1Columns + j + 1;

			MatrixDynMemoryMalloc<double> mat2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					mat2(i, j) = i*matrix2Columns + j + 1;

			MatrixDynMemoryMalloc<double> mat3(matrix3Rows, matrix3Columns);

			boost::timer::cpu_timer timer;
			timer.stop();

			timer.start();
			mat3 = mat1 * mat2;
			timer.stop();

			boost::timer::cpu_times timesNaive = timer.elapsed();
			printf("Timings for matrix  multiplication using my vector is %s\n", timer.format().c_str());


			static const double resultsArr[] = { 9,12,15,19,26,33,29,40,51 };

			for (int i = 0; i < matrix3Rows; i++)
				for (int j = 0; j < matrix3Columns; j++)
					Assert::AreEqual(mat3(i, j), resultsArr[i*matrix2Columns + j]);

		}


		TEST_METHOD(MultVecMatrix)
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

			Matrix<double> mat3(matrix3Rows, matrix3Columns);

			boost::timer::cpu_timer timer;
			timer.stop();

			timer.start();
			mat3 = mat1 * mat2;
			timer.stop();

			boost::timer::cpu_times timesNaive = timer.elapsed();
			printf("Timings for matrix  multiplication using my vector is %s\n", timer.format().c_str());


			static const double resultsArr[] = { 9,12,15,19,26,33,29,40,51 };

			for (int i = 0; i < matrix3Rows; i++)
				for (int j = 0; j < matrix3Columns; j++)
					Assert::AreEqual(mat3(i, j), resultsArr[i*matrix2Columns + j]);

		}

		TEST_METHOD(MultTimingComparisonsMatrix)
		{
			std::ofstream logFile("logFile.txt");

			const int matrix1Rows = 100;
			const int matrix1Columns = 200;

			const int matrix2Rows = 200;
			const int matrix2Columns = 300;

			const int matrix3Rows = 100;
			const int matrix3Columns = 300;

			Matrix<double> mat1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					mat1(i, j) = i*matrix1Columns + j + 1;

			Matrix<double> mat2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					mat2(i, j) = i*matrix2Columns + j + 1;

			Matrix<double> mat3(matrix3Rows, matrix3Columns, 0);

			boost::timer::cpu_timer timer;
			timer.stop();

			timer.start();
			mat3 = mat1 * mat2;
			timer.stop();

			boost::timer::cpu_times timesNaive = timer.elapsed();
			std::string vectorImpTime = timer.format();
			logFile << "Timings for matrix  multiplication using my vector implementation is " + vectorImpTime << std::endl;
			//printf("Timings for matrix  multiplication using my vector implementation is %s\n", vectorImpTime);

			Eigen::MatrixXd eigenMat1(matrix1Rows, matrix1Columns);
			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					eigenMat1(i, j) = i*matrix1Columns + j + 1;

			Eigen::MatrixXd eigenMat2(matrix2Rows, matrix2Columns);
			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					eigenMat2(i, j) = i*matrix2Columns + j + 1;

			timer.stop();

			timer.start();
			Eigen::MatrixXd eigenMat3;// = Eigen::MatrixXd::Zero(matrix3Rows, matrix3Columns);
			eigenMat3 = eigenMat1*eigenMat2;
			timer.stop();

			timesNaive = timer.elapsed();
			std::string eigenImpTime = timer.format();
			logFile << "Timings for matrix  multiplication using eigen implementation is " + eigenImpTime << std::endl;
			//printf("Timings for matrix  multiplication using eigen implementation is %s\n", eigenImlTime);

			//vectorImpTime is around 20 times slower than eigenImpTime. 
			//Now implement a Matrix class using raw memory and then compare its timings

			MatrixDynMemoryNew<double> matDynNew1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					matDynNew1(i, j) = i*matrix1Columns + j + 1;

			MatrixDynMemoryNew<double> matDynNew2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					matDynNew2(i, j) = i*matrix2Columns + j + 1;

			MatrixDynMemoryNew<double> matDynNew3(matrix3Rows, matrix3Columns, 0);

			timer.stop();

			timer.start();
			matDynNew3 = matDynNew1 * matDynNew2;
			timer.stop();

			timesNaive = timer.elapsed();
			std::string dynNewImpTime = timer.format();
			logFile << "Timings for matrix  multiplication using my dynamic memory new implementation is " + dynNewImpTime << std::endl;

			MatrixDynMemoryMalloc<double> matDynMalloc1(matrix1Rows, matrix1Columns);

			for (int i = 0; i < matrix1Rows; i++)
				for (int j = 0; j < matrix1Columns; j++)
					matDynNew1(i, j) = i*matrix1Columns + j + 1;

			MatrixDynMemoryMalloc<double> matDynMalloc2(matrix2Rows, matrix2Columns);

			for (int i = 0; i < matrix2Rows; i++)
				for (int j = 0; j < matrix2Columns; j++)
					matDynNew2(i, j) = i*matrix2Columns + j + 1;

			MatrixDynMemoryMalloc<double> matDynMalloc3(matrix3Rows, matrix3Columns, 0);

			timer.stop();

			timer.start();
			matDynNew3 = matDynNew1 * matDynNew2;
			timer.stop();

			timesNaive = timer.elapsed();
			std::string dynMallocImpTime = timer.format();
			logFile << "Timings for matrix  multiplication using my dynamic memory malloc implementation is " + dynMallocImpTime << std::endl;

		}
	};
}