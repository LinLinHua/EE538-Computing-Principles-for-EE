#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using testing::UnorderedElementsAre;

TEST(findResourceTest, BasicTest)
{

  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  auto result = findResource(candidates, target);
  EXPECT_THAT(result, UnorderedElementsAre(UnorderedElementsAre(7),
                                           UnorderedElementsAre(2, 2, 3)));
}

TEST(findResourceTest, BasicTest2)
{

  std::vector<int> candidates = {1, 4, 6};
  int target = 6;
  auto result = findResource(candidates, target);
  EXPECT_THAT(result,
              UnorderedElementsAre(UnorderedElementsAre(1, 1, 1, 1, 1, 1),
                                   UnorderedElementsAre(1, 1, 4),
                                   UnorderedElementsAre(6)));
}

TEST(findResourceTest, EmptyCandidates)
{

  std::vector<int> candidates = {};
  int target = 7;
  auto result = findResource(candidates, target);
  EXPECT_EQ(result.empty(), 1);
}

TEST(findResourceTest, ZeroTarget)
{

  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 0;
  auto result = findResource(candidates, target);
  EXPECT_EQ(result.empty(), 1);
}

TEST(findResourceTest, Impossible)
{

  std::vector<int> candidates = {2, 4, 6, 8};
  int target = 5;
  auto result = findResource(candidates, target);
  EXPECT_EQ(result.empty(), 1);
}