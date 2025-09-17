#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(FastestToTargetTests, YouFaster) {
  std::vector<std::vector<char>> grid = {//
                                         {'y', '0', 'f'},
                                         {'0', '1', '0'},
                                         {'t', '0', '0'}};
  EXPECT_EQ(fastestToTarget(grid), 1); // You reach faster
}

TEST(FastestToTargetTests, FriendFaster) {
  std::vector<std::vector<char>> grid = {//
                                         {'y', '1', '0', 't'},
                                         {'0', '1', '1', '0'},
                                         {'0', '0', 'f', '0'}};
  EXPECT_EQ(fastestToTarget(grid), 2); // Friend reaches faster
}

TEST(FastestToTargetTests, Tie) {
  std::vector<std::vector<char>> grid = {//
                                         {'y', '0', 'f'},
                                         {'0', '1', '0'},
                                         {'0', 't', '0'}};
  EXPECT_EQ(fastestToTarget(grid), 3); // Tie
}

TEST(FastestToTargetTests, ImpossibleForBoth) {
  std::vector<std::vector<char>> grid = {//
                                         {'y', '1', 'f'},
                                         {'1', '1', '1'},
                                         {'t', '1', '0'}};
  EXPECT_EQ(fastestToTarget(grid), -1); // Impossible for both
}

TEST(FastestToTargetTests, LargeGridWithObstacles) {
  std::vector<std::vector<char>> grid = {
      //
      {'y', '0', '0', '0', '0', '0', '0', '0', '0', 'f'},
      {'0', '1', '1', '1', '1', '1', '1', '1', '0', '0'},
      {'0', '1', '0', '0', '0', '0', '0', '1', '0', '0'},
      {'0', '1', '0', '1', '1', '1', '0', '1', '1', '0'},
      {'0', '0', '0', '0', 't', '0', '0', '0', '0', '0'},
      {'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
      {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}};
  EXPECT_EQ(fastestToTarget(grid), 1); // You are faster, assuming a clever path
}
