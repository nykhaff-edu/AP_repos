#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_2/lab_05_2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1A) {
			double t = A(2, 2, 4);
			Assert::AreEqual(8.0, t, 0.0000000001);
		}
		TEST_METHOD(TestMethod2A) {
			double t = A(0, 1, 1);
			Assert::AreEqual(0.0, t, 0.0000000001);
		}
		TEST_METHOD(TestMethod1S) {
			int n;
			double t = S(0, 0.001, n, 0);
			Assert::AreEqual(1.0, t, 0.0000000001);
		}
		TEST_METHOD(TestMethod2S) {
			int n;
			double s = S(2, 0.000001, n, 0);
			Assert::AreEqual(exp(4), s, 0.0001);
		}
	};
}
