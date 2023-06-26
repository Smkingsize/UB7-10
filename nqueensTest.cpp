#include <gtest/gtest.h>

#include "nqueens.hpp"

int create_nqueens_and_count(int n) {
  NQueens queens(n);
  return queens.count_solutions();
}

int create_nqueens_and_count_fundamental(int n) {
  NQueens queens(n);
  return queens.count_fundamental_solutions();
}

TEST(NQueensTest, ValueTest) {
  ASSERT_EQ(create_nqueens_and_count(4), 2);
  ASSERT_EQ(create_nqueens_and_count(5), 10);
  ASSERT_EQ(create_nqueens_and_count(6), 4);
  ASSERT_EQ(create_nqueens_and_count(7), 40);
  ASSERT_EQ(create_nqueens_and_count(8), 92);
}
TEST(NQueensTest, FundamentalSolutionsTest) {
  ASSERT_EQ(create_nqueens_and_count_fundamental(4), 1);
  ASSERT_EQ(create_nqueens_and_count_fundamental(5), 2);
  ASSERT_EQ(create_nqueens_and_count_fundamental(6), 1);
  ASSERT_EQ(create_nqueens_and_count_fundamental(7), 6);
  ASSERT_EQ(create_nqueens_and_count_fundamental(8), 12);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
