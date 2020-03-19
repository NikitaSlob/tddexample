#include "pch.h"
#include "CppUnitTest.h"
#include <list>
#include "../part2c++/LinearEquation.cpp"
#include "../part2c++/SystemOfLinearEquation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		double* array = new double[4]{ 1, 2, 3, 4 };
		TEST_METHOD(TestInput1)
		{
			LinearEquation l1 = LinearEquation(3);
			Assert::AreEqual(l1.indexes[0], l1.indexes[1]);
		}
		TEST_METHOD(TestInput2)
		{
			LinearEquation l1 = LinearEquation("1.2 2.1 3 4", 4);
			Assert::AreEqual(l1.indexes[0], 1.2);
		}
		TEST_METHOD(TestInput3)
		{
			LinearEquation l1 = LinearEquation(array, 4);
			Assert::AreEqual(l1.indexes[0], 1.0);
		}
		TEST_METHOD(TestSet1)
		{
			LinearEquation l1 = LinearEquation(array, 4);
			l1.SetIndexes(1);
			Assert::AreEqual(l1.indexes[3], 1.0);
		}
		TEST_METHOD(TestSet2)
		{
			LinearEquation l1 = LinearEquation(array, 4);
			l1.SetIndexesRandom();
			Assert::AreNotEqual(l1.indexes[2], 2.0);
		}
		TEST_METHOD(TestOperator1)
		{
			LinearEquation l = LinearEquation(array, 4);
			l = l+l;
			Assert::AreEqual(l.indexes[0], 2.0);
		}
		TEST_METHOD(TestOperator2)
		{
			LinearEquation l = LinearEquation(array, 4);
			l = l - l;
			Assert::AreEqual(l.indexes[0], 0.0);
		}
		TEST_METHOD(TestOperator3)
		{
			LinearEquation l = LinearEquation(array, 4);
			l = l * 2;
			Assert::AreEqual(l.indexes[0], 2.0);
		}
		TEST_METHOD(TestOperator4)
		{
			LinearEquation l = LinearEquation(array, 4);
			l = 2 * l ;
			Assert::AreEqual(l.indexes[0], 2.0);
		}
		TEST_METHOD(TestOperator5)
		{
			LinearEquation l = LinearEquation(array, 4);
			Assert::AreEqual(l==l,true);
		}
		TEST_METHOD(TestOperator6)
		{
			LinearEquation l = LinearEquation(array, 4);
			Assert::AreEqual(l != l, false);
		}
		TEST_METHOD(TestOperator7)
		{
			LinearEquation l = LinearEquation(array, 4);
			Assert::AreEqual(l != l, false);
		}
		TEST_METHOD(TestOperator8)
		{
			LinearEquation l = LinearEquation("0 0 0 4", 4);
			Assert::AreEqual((bool)l, false);
		}
		TEST_METHOD(TestOperator9)
		{
			LinearEquation l = LinearEquation(array, 4);
			Assert::AreEqual((bool)l, true);
		}
		TEST_METHOD(TestOperator10)
		{
			LinearEquation l = LinearEquation(array, 4);
			Assert::AreEqual(-l.indexes[0], -1.0);
		}
		TEST_METHOD(FailWithWrongArguments1)
		{
			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				LinearEquation l1 = LinearEquation(array, 4);
				LinearEquation l2 = LinearEquation(10);
				l1 = l1 + l2;
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments2)
		{
			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				LinearEquation l1 = LinearEquation(array, 4);
				LinearEquation l2 = LinearEquation(10);
				l1 = l1 - l2;
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments3)
		{
			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				LinearEquation l1 = LinearEquation(array, 4);
				LinearEquation l2 = LinearEquation(10);
				bool b = (l1 == l2);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments4)
		{
			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				LinearEquation l1 = LinearEquation(array, 4);
				LinearEquation l2 = LinearEquation(10);
				bool b = l1 != l2;
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(TestSystem1)
		{
			LinearEquation l1 = LinearEquation("2 4 1 36", 4);
			LinearEquation l2 = LinearEquation("5 2 1 47", 4);
			LinearEquation l3 = LinearEquation("2 3 4 37", 4);
			SystemOfLinearEquation slu = SystemOfLinearEquation(3);
			slu[0] = l1;
			slu[1] = l2;
			slu[2] = l3;
			double *x = slu.gauss();
			Assert::AreEqual(x[0],7.0);
		}
		TEST_METHOD(FailWithWrongArguments5)
		{
			auto func = []
			{
				LinearEquation l1 = LinearEquation("2 4 1 36", 4);
				LinearEquation l2 = LinearEquation("5 2 1 47", 4);
				LinearEquation l3 = LinearEquation(4);
				SystemOfLinearEquation slu = SystemOfLinearEquation(3);
				slu[0] = l1;
				slu[1] = l2;
				slu[2] = l3;
				slu[0].coutl();
				slu[1].coutl();
				slu[2].coutl();
				double *x = slu.gauss();
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments6)
		{
			auto func = []
			{
				LinearEquation l1 = LinearEquation("2 4 1 36", 4);
				LinearEquation l2 = LinearEquation("5 2 1 47", 4);
				LinearEquation l3 = LinearEquation("0 0 0 1",4);
				SystemOfLinearEquation slu = SystemOfLinearEquation(3);
				slu[0] = l1;
				slu[1] = l2;
				slu[2] = l3;
				double *x = slu.gauss();
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments7)
		{
			auto func = []
			{
				LinearEquation l1 = LinearEquation("2 4 1 36", 4);
				LinearEquation l2 = LinearEquation("5 2 1 47", 4);
				LinearEquation l3 = LinearEquation(4);
				SystemOfLinearEquation slu = SystemOfLinearEquation(3);
				slu[3] = l1;
			};
			Assert::ExpectException<out_of_range>(func);
		}
		TEST_METHOD(TestSystem2)
		{
			LinearEquation l1 = LinearEquation(4);
			LinearEquation l2 = LinearEquation(4);
			SystemOfLinearEquation slu = SystemOfLinearEquation(3);
			slu[0] = l1;
			slu[1] = l2;
			Assert::AreEqual(slu[0].indexes[1], slu[1].indexes[3]);
		}
	};
}
