#include "q.h"

#include <iostream>
#include <vector>
#include "q.h"
#include <vector>

// 1. Implement knapSack01NoDynamicProgramming:
int knapSack01NoDynamicProgramming(const std::vector<int> &weights,
                                   const std::vector<int> &values, int w) {
  return knapSack01NoDynamicProgramming_Helper(weights, values, w, 0);
}

// 2. Define knapSack01NoDynamicProgramming_Helper and implement it in the .cc
// file. This function takes similar arguments like
// knapSack01NoDynamicProgramming with some extra helper parameters:
int knapSack01NoDynamicProgramming_Helper(const std::vector<int> &weights,
                                          const std::vector<int> &values,
                                          int w,
                                          int i) {
  // Base case: no items left or no remaining capacity
  if (i >= weights.size() || w <= 0) return 0;

  // If item too heavy, skip it
  if (weights[i] > w) {
    return knapSack01NoDynamicProgramming_Helper(weights, values, w, i + 1);
  }

  // Option 1: include current item
  int include = values[i] +
                knapSack01NoDynamicProgramming_Helper(weights, values, w - weights[i], i + 1);

  // Option 2: exclude current item
  int exclude = knapSack01NoDynamicProgramming_Helper(weights, values, w, i + 1);

  // Return the greater of the two
  if (include > exclude) return include;
  return exclude;
}


// 3. Implement knapSack01Memo:
// This function just sets up the memoization table and calls the helper.
int knapSack01Memo(const std::vector<int> &weights,
                   const std::vector<int> &values, int w) {
  int n = weights.size();
  // Initialize memo table with -1 (means "not computed")
  std::vector<std::vector<int>> memo(n + 1, std::vector<int>(w + 1, -1));
  return knapSack01Memo_Helper(weights, values, w, 0, memo);
}

// 4. Implement knapSack01Memo_Helper:
int knapSack01Memo_Helper(const std::vector<int> &weights,
                          const std::vector<int> &values,
                          int w, int i,
                          std::vector<std::vector<int>> &memo) {
  // Base case: no items left or no capacity
  if (i >= weights.size() || w <= 0) return 0;

  // If already computed, return memoized value
  if (memo[i][w] != -1) return memo[i][w];

  int result;

  // If item is too heavy, skip it
  if (weights[i] > w) {
    result = knapSack01Memo_Helper(weights, values, w, i + 1, memo);
  } else {
    // Option 1: include current item
    int include = values[i] +
                  knapSack01Memo_Helper(weights, values, w - weights[i], i + 1, memo);

    // Option 2: exclude current item
    int exclude = knapSack01Memo_Helper(weights, values, w, i + 1, memo);

    // Choose maximum
    result = (include > exclude) ? include : exclude;
  }

  // Save result to memo table
  memo[i][w] = result;
  return result;
}


// 3. Implement knapSack01Tablulation. Use a two-dimensional vector for the table.
int knapSack01Tablulation(const std::vector<int> &weights,
                          const std::vector<int> &values, int w) {
  int n = weights.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(w + 1, 0));

  // Build table bottom-up
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (weights[i - 1] > j) {
        // Cannot include item i-1
        dp[i][j] = dp[i - 1][j];
      } else {
        // Include or exclude item i-1
        int include = values[i - 1] + dp[i - 1][j - weights[i - 1]];
        int exclude = dp[i - 1][j];
        dp[i][j] = (include > exclude) ? include : exclude;
      }
    }
  }

  return dp[n][w];  // Max value using all items and full capacity
}