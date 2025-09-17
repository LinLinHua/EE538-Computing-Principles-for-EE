#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

// -------------------- Fibonacci Tests --------------------

TEST(FibonacciTest, BaseCases) {
  EXPECT_EQ(Fibonacci(0), 1);
  EXPECT_EQ(Fibonacci(1), 1);
}

TEST(FibonacciTest, SmallValues) {
  EXPECT_EQ(Fibonacci(5), 8);
  EXPECT_EQ(Fibonacci(10), 89);
  EXPECT_EQ(Fibonacci(15), 987);
}

// -------------------- Coin Change Memoization Tests --------------------

TEST(CoinChangeMemoTest, BasicCase) {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  int expected = 3;  // 5+5+1
  EXPECT_EQ(CoinChangeMemo(coins, amount), expected);
}

TEST(CoinChangeMemoTest, NoSolution) {
  std::vector<int> coins = {2};
  int amount = 3;
  int expected = -1;
  EXPECT_EQ(CoinChangeMemo(coins, amount), expected);
}

TEST(CoinChangeMemoTest, ExactMatch) {
  std::vector<int> coins = {2, 3};
  int amount = 6;
  int expected = 2;  // 3 + 3
  EXPECT_EQ(CoinChangeMemo(coins, amount), expected);
}

// -------------------- Coin Change Tabulation Tests --------------------

TEST(CoinChangeTabulationTest, BasicCase) {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  int expected = 3;
  EXPECT_EQ(CoinChangeTabulation(coins, amount), expected);
}

TEST(CoinChangeTabulationTest, NoSolution) {
  std::vector<int> coins = {4, 5};
  int amount = 3;
  int expected = -1;
  EXPECT_EQ(CoinChangeTabulation(coins, amount), expected);
}

TEST(CoinChangeTabulationTest, SingleCoinMatch) {
  std::vector<int> coins = {7};
  int amount = 14;
  int expected = 2;
  EXPECT_EQ(CoinChangeTabulation(coins, amount), expected);
}

TEST(CoinChangeTabulationTest, ZeroAmount) {
  std::vector<int> coins = {1, 2, 3};
  int amount = 0;
  int expected = 0;
  EXPECT_EQ(CoinChangeTabulation(coins, amount), expected);
}
