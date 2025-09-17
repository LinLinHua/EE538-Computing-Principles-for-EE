#include "q.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <climits>
// Implement each function of `q.h` here.
// Returns the nth Fibonacci number using O(n) time and O(1) space
int Fibonacci(int n) {
  if (n == 0) return 1;
  if (n == 1) return 1;

  int prev = 1;  // F(0)
  int curr = 1;  // F(1)

  for (int i = 2; i <= n; ++i) {
    int next = prev + curr;
    prev = curr;
    curr = next;
  }

  return curr;
}



// Helper to access nth element of list<int> by reference
int& GetMemo(std::list<int>& memo, int index) {
  auto it = memo.begin();
  std::advance(it, index);
  return *it;
}

// Recursive memoized coin change using list<int> as memo
int CoinChangeMemo_Helper(std::vector<int>& coins, int amount,
                          std::list<int>& memo) {
  if (amount < 0) return INT_MAX;  // invalid path
  if (amount == 0) return 0;

  int& ref = GetMemo(memo, amount);
  if (ref != -1) return ref;  // already computed

  int min_coins = INT_MAX;
  for (int coin : coins) {
    int result = CoinChangeMemo_Helper(coins, amount - coin, memo);
    if (result != INT_MAX && result + 1 < min_coins) {
      min_coins = result + 1;
    }
  }

  ref = min_coins;
  return ref;
}

// Wrapper function
int CoinChangeMemo(std::vector<int>& coins, int amount) {
  std::list<int> memo(amount + 1, -1);  // -1 means "not computed"
  int result = CoinChangeMemo_Helper(coins, amount, memo);
  return (result == INT_MAX) ? -1 : result;
}


// Helper to get reference to table[i] from std::list<int>
int& GetTable(std::list<int>& table, int index) {
  auto it = table.begin();
  std::advance(it, index);
  return *it;
}

int CoinChangeTabulation(std::vector<int>& coins, int amount) {
  std::list<int> table(amount + 1, INT_MAX);
  GetTable(table, 0) = 0;  // 0 coins needed to make amount 0

  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (coin <= i) {
        int prev = GetTable(table, i - coin);
        if (prev != INT_MAX) {
          int& curr = GetTable(table, i);
          if (prev + 1 < curr) {
            curr = prev + 1;
          }
        }
      }
    }
  }

  int result = GetTable(table, amount);
  return (result == INT_MAX) ? -1 : result;
}
