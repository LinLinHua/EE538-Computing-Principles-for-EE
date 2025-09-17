#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"
#include <climits>
const int INF = INT_MAX;

// TODO: Add more tests below!


std::map<int, std::set<std::pair<int, int>>> BuildSampleGraph() {
  return {
      {0, {{1, 4}, {2, 5}}},
      {1, {{2, -2}}},
      {2, {{3, 3}}},
      {3, {{1, 1}}},
  };
}

TEST(GraphTest, GetPredecessors) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  auto result = g.GetPredecessors();

  EXPECT_EQ(result[0], std::set<int>());         
  EXPECT_EQ(result[1], std::set<int>({0, 3}));
  EXPECT_EQ(result[2], std::set<int>({0, 1}));
  EXPECT_EQ(result[3], std::set<int>({2}));
}

TEST(GraphTest, GetEdges) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  std::set<std::pair<int, int>> expected = {
      {0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 1}};

  EXPECT_EQ(g.GetEdges(), expected);
}

TEST(GraphTest, GetWeight) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  EXPECT_EQ(g.GetWeight(0, 1), 4);
  EXPECT_EQ(g.GetWeight(1, 2), -2);
  EXPECT_EQ(g.GetWeight(3, 1), 1);
  EXPECT_EQ(g.GetWeight(2, 0), INT_MAX);  // No such edge
}

TEST(GraphTest, GetMinWeight) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  EXPECT_EQ(g.GetMinWeight(), -2);
}

TEST(GraphTest, Dijkstra) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  std::vector<long> expected = {0, 4, 2, 5};
  EXPECT_EQ(g.Dijkstra(0), expected);
}

TEST(GraphTest, BellmanFord) {
  auto graph_data = BuildSampleGraph();
  Graph g(graph_data);

  std::vector<long> expected = {0, 4, 2, 5};
  EXPECT_EQ(g.BellmanFord(0), expected);
}
