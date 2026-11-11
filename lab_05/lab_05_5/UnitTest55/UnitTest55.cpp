#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_5/lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55 {
    TEST_CLASS(UnitTest55) {
    public:
        
        TEST_METHOD(TestMethod1) {
            int d = 0;
            int r = C(5, 2, 1, d);
            Assert::AreEqual(10, r);
            Assert::AreEqual(5, d);
        }

        TEST_METHOD(TestMethod2) {
            int d = 0;
            int r = C(1, 0, 1, d);
            Assert::AreEqual(1, r);
            Assert::AreEqual(1, d);
        }

        TEST_METHOD(TestMethod3) {
            int d = 0;
            int r = C(2, 2, 1, d);
            Assert::AreEqual(1, r);
            Assert::AreEqual(1, d);
        }

        TEST_METHOD(TestMethod4) {
            int d = 0;
            int r = C(10, 1, 1, d);
            Assert::AreEqual(10, r);
            Assert::AreEqual(10, d);
        }
    };
}
