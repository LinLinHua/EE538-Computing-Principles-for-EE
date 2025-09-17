
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

/*
You and your friend are located on a grid where some cells may be blocked. Each
cell in the grid may be marked as:
- 'y' for your starting position
- 'f' for your friend's starting position
- 't' for the target position
- '0' for open cells
- '1' for blocked cells.

Given this grid, write a function to determine who can
reach the target first.

- You and your friend can move up, down, left, and right.
- You and your friend start moving simultaneously and at the same speed.
- You and your friend move with the same speed and start at the same
time.
- The initial positions marked as 'y', 'f', and 't' are distinct and located on
cells marked as '0'.
- When you start moving, it is possible that you and your friend be in the
same cell at the same time.


Output:

Return 1 if you can reach the target faster than your friend.
Return 2 if your friend can reach the target faster than you.
Return 3 if both of you can reach the target at the same time.
Return -1 if it is impossible for both you and your friend to reach the target.


Example 1:
Input:
grid = [
  ['y', '0', 'f'],
  ['0', '1', '0'],
  ['t', '0', '0']
]
Output: 1
Explanation:
You start at the top-left corner, your friend starts at the top-right corner,
and the target is located at the bottom-left corner. The path for you is
shorter, allowing you to reach the target faster than your friend.


Example 2:
grid = [
  ['f', '0', '1', 't'],
  ['1', '1', '0', '0'],
  ['y', '0', '0', '0']
]
output: 1
Explanation: your friend's path to 't' is blocked.


Example 3:
grid = [
  ['y', '0', 'f'],
  ['1', '1', '0'],
  ['t', '1', '0']
]
Output: -1
Explanation: The path to 't' is blocked for both of you.
*/

int fastestToTarget(std::vector<std::vector<char>> &grid);
