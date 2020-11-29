#include "gtest/gtest.h"


//#include "seven_mock_op.hpp"
//#include "neg_mock_op.hpp"
//#include "zero_mock_op.hpp"
//#include "op_test.hpp"
#include "rand_test.hpp"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "add_test.hpp"
#include "op_test.hpp"
#include "sub_test.hpp"
#include "pow_test.hpp"
#include "VectorContainer_Test.hpp"
#include "SelectionSort_Test.hpp"
#include "bubble_test.hpp"
#include "list_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
