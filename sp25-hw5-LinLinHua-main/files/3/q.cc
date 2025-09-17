#include "q.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
// Implement each function of `q.h` here.
// Helper function that uses DFS to generate all possible password combinations
// from lowercase letters up to the given max length.
// It adds to the result only those passwords that:
// 1. Pass TryPassword()
// 2. Do NOT contain any substring from the dictionary (checked via IsInDictionary)
// The main function that initializes the recursion
std::unordered_set<std::string> FindAllPasswords(BlackBox& blackbox,
                                                 int max_length) {
  std::unordered_set<std::string> results;
  std::string current_password;
  FindAllPasswords_aux(blackbox, max_length, current_password, results);
  return results;
}

// A recursive function that finds all the correct valid_passwords that do not
// contain a word in the dictionary and puts them in the `results` parameter.
void FindAllPasswords_aux(BlackBox& blackbox, int max_length,
                          std::string& current_password,
                          std::unordered_set<std::string>& results) {
  if (!current_password.empty()) {
    std::string candidate = current_password;
    if (blackbox.TryPassword(candidate) && !blackbox.IsInDictionary(candidate)) {
      results.insert(candidate);
    }
  }

  if (current_password.length() == max_length) return;

  for (char c = 'a'; c <= 'z'; ++c) {
    current_password.push_back(c);
    FindAllPasswords_aux(blackbox, max_length, current_password, results);
    current_password.pop_back();
  }
}