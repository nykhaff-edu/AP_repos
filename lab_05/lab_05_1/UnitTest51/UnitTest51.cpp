#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_1/lab_05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51 {
	TEST_CLASS(UnitTest51) {
	public:
		
		TEST_METHOD(TestMethod1) {
			double t;
			t = k(0, 1);
			Assert::AreEqual(t, cos(1.0), 0.0000000001);
		}
		TEST_METHOD(TestMethod2) {
			double t;
			t = k(1, 0);
			Assert::AreEqual(t, sin(1.0) + 1.0), 0.0000000001;
		}
	};
}
