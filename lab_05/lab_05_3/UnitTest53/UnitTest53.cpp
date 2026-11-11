#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_3/lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
	TEST_CLASS(UnitTest53)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t = h(0);
			Assert::AreEqual(1.0, t, 0.0000000001);
		}
		TEST_METHOD(TestMethod2)
		{
			double t = h(1);
			Assert::AreEqual((cos(1.0) + 1) / (pow(cos(1.0), 2) + 1), t, 0.0000000001);
		}
		TEST_METHOD(TestMethod3)
		{
			double t = h(3.14159265358979);
			Assert::AreEqual(0.0, t, 0.0000000001);
		}
	};
}
