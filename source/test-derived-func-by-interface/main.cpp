#include "binary_search_loop.h"
#include "binary_search_recursive.h"
#include "gtest/gtest.h"

namespace {
template <class T> BinarySearch *CreateBinarySearch();

template <> BinarySearch *CreateBinarySearch<BinarySearchLoop>() {
  return new BinarySearchLoop();
}

template <> BinarySearch *CreateBinarySearch<BinarySearchRecursive>() {
  return new BinarySearchRecursive();
}

template <class T> class BinarySearchTest : public testing::Test {
protected:
  BinarySearchTest() : algo_(CreateBinarySearch<T>()) {}
  ~BinarySearchTest() override { delete algo_; }
  BinarySearch *const algo_;
};

using testing::Types;
typedef Types<BinarySearchLoop, BinarySearchRecursive> BinarySearchImplement;

TYPED_TEST_SUITE(BinarySearchTest, BinarySearchImplement);

TYPED_TEST(BinarySearchTest, PositiveInteger) {
  std::vector<int> SortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(4, this->algo_->search(SortedArray, 5));
  EXPECT_EQ(5, this->algo_->search(SortedArray, 6));
  EXPECT_EQ(0, this->algo_->search(SortedArray, 1));
  EXPECT_EQ(8, this->algo_->search(SortedArray, 9));
}

TYPED_TEST(BinarySearchTest, NegativeInteger) {
  std::vector<int> SortedArray = {-8, -7, -6, -5, -4, -3, -2, -1};
  EXPECT_EQ(+6, this->algo_->search(SortedArray, -2));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, +0));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, -9));
}

TYPED_TEST(BinarySearchTest, Integer) {
  std::vector<int> SortedArray = {-1, 0, 3, 5, 9, 12};
  EXPECT_EQ(+4, this->algo_->search(SortedArray, 9));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, 2));
}

TYPED_TEST(BinarySearchTest, SingleElement) {
  std::vector<int> SortedArray = {5};
  EXPECT_EQ(+0, this->algo_->search(SortedArray, 5));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, 1));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, 6));
}

TYPED_TEST(BinarySearchTest, TwoElementsOnly) {
  std::vector<int> SortedArray = {1, 5};
  EXPECT_EQ(+1, this->algo_->search(SortedArray, 5));
  EXPECT_EQ(+0, this->algo_->search(SortedArray, 1));
  EXPECT_EQ(-1, this->algo_->search(SortedArray, 2)); // Not in the array.
  EXPECT_EQ(-1, this->algo_->search(SortedArray, 7)); // Not in the array.
}

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int Ret = RUN_ALL_TESTS();
  return Ret;
}
