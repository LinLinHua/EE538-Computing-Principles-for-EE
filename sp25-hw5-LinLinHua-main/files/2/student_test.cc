#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
// Test case 1: Simple input
TEST(KnapsackTest, BasicCase) {
  std::vector<int> weights = {1, 3, 4};
  std::vector<int> values = {15, 20, 30};
  int w = 4;
  int expected = 35;

  EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, w), expected);
  EXPECT_EQ(knapSack01Memo(weights, values, w), expected);
  EXPECT_EQ(knapSack01Tablulation(weights, values, w), expected);
}

// Test case 2: All items too heavy
TEST(KnapsackTest, AllItemsTooHeavy) {
  std::vector<int> weights = {5, 6, 7};
  std::vector<int> values = {10, 20, 30};
  int w = 4;
  int expected = 0;

  EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, w), expected);
  EXPECT_EQ(knapSack01Memo(weights, values, w), expected);
  EXPECT_EQ(knapSack01Tablulation(weights, values, w), expected);
}

// Test case 3: Capacity = 0
TEST(KnapsackTest, ZeroCapacity) {
  std::vector<int> weights = {1, 2, 3};
  std::vector<int> values = {10, 20, 30};
  int w = 0;
  int expected = 0;

  EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, w), expected);
  EXPECT_EQ(knapSack01Memo(weights, values, w), expected);
  EXPECT_EQ(knapSack01Tablulation(weights, values, w), expected);
}

// Test case 4: Only one item fits
TEST(KnapsackTest, OnlyOneItemFits) {
  std::vector<int> weights = {3, 4, 5};
  std::vector<int> values = {40, 50, 60};
  int w = 4;
  int expected = 50;

  EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, w), expected);
  EXPECT_EQ(knapSack01Memo(weights, values, w), expected);
  EXPECT_EQ(knapSack01Tablulation(weights, values, w), expected);
}

// Test case 5: All items can be taken
TEST(KnapsackTest, AllItemsFit) {
  std::vector<int> weights = {1, 2, 3};
  std::vector<int> values = {10, 15, 40};
  int w = 6;
  int expected = 65;

  EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, w), expected);
  EXPECT_EQ(knapSack01Memo(weights, values, w), expected);
  EXPECT_EQ(knapSack01Tablulation(weights, values, w), expected);
}