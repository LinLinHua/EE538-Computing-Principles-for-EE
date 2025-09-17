#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

// Given the following inputs:

// - Tasks: A vector of unique integers where element i represents the resource
// consumption of a task i.
// - Total Resource Limit: An integer specifying the total amount of resources
// available.

// Objective: Determine all unique combinations of tasks that sum up
// to exactly the total resource limit.

// Note: Each task can be allocated multiple times.
// Note: Your output need not be sorted.

// Example 1:

// Tasks and Resource Costs: [task0 = 3, task1 = 4, task2 = 7]
// Resource Limit: 14
// Your output should be a two-dimensional vector:
// [[3, 3, 3, 3, 2], [3, 3, 4, 4], [3, 4, 7], [7, 7]].

// Explanation:
// - 4 task0 + 1 task1 (3+3+3+3+2).
// - 2 task0 + 2 task1 (3+3+4+4)
// - 1 task0 + 1 task1 + 1 task2 (3+4+7)
// - 2 task2 (7+7)

// Example 2:

// Tasks and Resource Costs: [task0 = 2, task1 = 5, task2 = 9]
// Resource Limit: 18

// Your output should be a two-dimensional vector:
// [[2, 2, 2, 2, 2, 2, 2, 2, 2], [2, 2, 2, 2, 5, 5], [2, 2, 5, 9], [5, 5, 8], [9, 9]].
// Possible Combinations:
// - 9 task0 (2+2+2+2+2+2+2+2+2)
// - 4 task0 + 2 task1 (2+2+2+2+5+5)
// - 2 task0 + 1 task1 + 1 task2 (2+2+5+9)
// - 2 task1 + 1 task2 (5+5+8)
// - 2 task2 (9+9)

std::vector<std::vector<int>> findResource(std::vector<int> &tasks, int limit);
