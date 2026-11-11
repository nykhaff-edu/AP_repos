#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_4/lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54 {
    TEST_CLASS(UnitTest54) {
    public:

        TEST_METHOD(TestMethod1) {
            double t;

            t = rec_d_par_d(3, 0);
            Assert::AreEqual(t, 5.50177, 0.0001);

            t = rec_d_par_up(1, 3, 0);
            Assert::AreEqual(t, 5.50177, 0.0001);

            t = rec_up_par_d(3);
            Assert::AreEqual(t, 5.50177, 0.0001);

            t = rec_up_par_up(1, 3);
            Assert::AreEqual(t, 5.50177, 0.0001);

            t = c_iter(1, 3);
            Assert::AreEqual(t, 5.50177, 0.0001);
        }
    };
}