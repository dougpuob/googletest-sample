#include "binary_search_loop.h"
#include "binary_search_recursive.h"
#include "gtest/gtest.h"

template <class T>
struct TestBinarySearch : public ::testing::Test {
  static T Instance;
};

TYPED_TEST_CASE_P(TestBinarySearch);

TYPED_TEST_P(TestBinarySearch, PositiveInteger) {
  std::vector<int> SortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(4, Instance.search(SortedArray, 5));
  ASSERT_EQ(5, Instance.search(SortedArray, 6));
  ASSERT_EQ(0, Instance.search(SortedArray, 1));
  ASSERT_EQ(8, Instance.search(SortedArray, 9));
}

TYPED_TEST_P(TestBinarySearch, NegativeInteger) {
  std::vector<int> SortedArray = {-8, -7, -6, -5, -4, -3, -2, -1};
  EXPECT_EQ(+6, Instance.search(SortedArray, -2));
  EXPECT_EQ(-1, Instance.search(SortedArray, +0));
  EXPECT_EQ(-1, Instance.search(SortedArray, -9));
}

TYPED_TEST_P(TestBinarySearch, Integer) {
  std::vector<int> SortedArray = {-1, 0, 3, 5, 9, 12};
  EXPECT_EQ(+4, Instance.search(SortedArray, 9));
  EXPECT_EQ(-1, Instance.search(SortedArray, 2));
}

TYPED_TEST_P(TestBinarySearch, SingleElement) {
  std::vector<int> SortedArray = {5};
  EXPECT_EQ(+0, Instance.search(SortedArray, 5));
  EXPECT_EQ(-1, Instance.search(SortedArray, 1));
  EXPECT_EQ(-1, Instance.search(SortedArray, 6));
}

TYPED_TEST_P(TestBinarySearch, TwoElementsOnly) {
  std::vector<int> SortedArray = {1, 5};
  EXPECT_EQ(+1, Instance.search(SortedArray, 5));
  EXPECT_EQ(+0, Instance.search(SortedArray, 1));
  EXPECT_EQ(-1, Instance.search(SortedArray, 2));  // Not in the array.
  EXPECT_EQ(-1, Instance.search(SortedArray, 7));  // Not in the array.
}

REGISTER_TYPED_TEST_CASE_P(TestBinarySearch,
                           PositiveInteger,
                           NegativeInteger,
                           Integer,
                           SingleElement,
                           TwoElementsOnly);

typedef ::testing::Types<BinarySearchLoop, BinarySearchRecursive> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(MyBinarySearchInstantiation,
                              TestBinarySearch,
                              MyTypes);

template <>
BinarySearchLoop TestBinarySearch<BinarySearchLoop>::Instance;

template <>
BinarySearchRecursive TestBinarySearch<BinarySearchRecursive>::Instance;

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int Ret = RUN_ALL_TESTS();
  return Ret;
}
