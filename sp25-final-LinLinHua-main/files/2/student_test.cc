#include <iostream>
#include <stdexcept>
#include <string>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

//-----------------------------------------------------------------------------
TEST(MovieTheaterAssignmentTests, AllDifferent)
{
  std::vector<int> students = {1, 2, 3};
  auto results = MovieTheaterAssignment(students);
  EXPECT_THAT(
      results,
      ::testing::UnorderedElementsAre(
          ::testing::ElementsAre(1, 2, 3), ::testing::ElementsAre(1, 3, 2),
          ::testing::ElementsAre(2, 1, 3), ::testing::ElementsAre(2, 3, 1),
          ::testing::ElementsAre(3, 1, 2), ::testing::ElementsAre(3, 2, 1)));
}

TEST(MovieTheaterAssignmentTests, TwoPairs)
{
  std::vector<int> students = {1, 1, 2, 3};
  auto results = MovieTheaterAssignment(students);
  EXPECT_THAT(results, ::testing::UnorderedElementsAre(
                           ::testing::ElementsAre(1, 2, 1, 3),
                           ::testing::ElementsAre(1, 3, 1, 2),
                           ::testing::ElementsAre(2, 1, 3, 1),
                           ::testing::ElementsAre(3, 1, 2, 1),
                           ::testing::ElementsAre(1, 2, 3, 1),
                           ::testing::ElementsAre(1, 3, 2, 1)));
}

TEST(MovieTheaterAssignmentTests, SamePairs)
{
  std::vector<int> students = {1, 1, 2, 2};
  auto results = MovieTheaterAssignment(students);
  EXPECT_THAT(results, ::testing::UnorderedElementsAre(
                           ::testing::ElementsAre(1, 2, 1, 2),
                           ::testing::ElementsAre(2, 1, 2, 1)));
}

TEST(MovieTheaterAssignmentTests, MajoritySame)
{
  std::vector<int> students = {1, 1, 1, 2};
  auto results = MovieTheaterAssignment(students);
  EXPECT_EQ(results.empty(), 1);
}

TEST(MovieTheaterAssignmentTests, MajoritySingleCountry)
{
  std::vector<int> students = {4, 4, 4, 4, 5, 6};
  auto results = MovieTheaterAssignment(students);
  EXPECT_EQ(results.empty(), 1);
}
