#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Test 1: Basic case with some passwords filtered out due to dictionary match
TEST(FindAllPasswordsTest, FilterOutDictionaryWords) {
  std::unordered_set<std::string> valid_passwords = {"abc", "xyz", "abb", "cdd"};
  std::unordered_set<std::string> dictionary = {"ab", "cd"};

  BlackBox box(valid_passwords, dictionary);
  int max_length = 3;

  std::unordered_set<std::string> expected = {"xyz"};
  auto result = FindAllPasswords(box, max_length);

  EXPECT_EQ(result, expected);
}

// Test 2: All passwords contain dictionary words → should return empty
TEST(FindAllPasswordsTest, AllPasswordsFilteredOut) {
  std::unordered_set<std::string> valid_passwords = {"aa", "bad", "sad", "bbb"};
  std::unordered_set<std::string> dictionary = {"a", "b"};

  BlackBox box(valid_passwords, dictionary);
  int max_length = 3;

  std::unordered_set<std::string> expected = {};
  auto result = FindAllPasswords(box, max_length);

  EXPECT_EQ(result, expected);
}

// Test 3: No dictionary words → all valid passwords should be returned
TEST(FindAllPasswordsTest, NoDictionaryWords) {
  std::unordered_set<std::string> valid_passwords = {"dog", "cat", "sun"};
  std::unordered_set<std::string> dictionary = {};

  BlackBox box(valid_passwords, dictionary);
  int max_length = 3;

  std::unordered_set<std::string> expected = {"dog", "cat", "sun"};
  auto result = FindAllPasswords(box, max_length);

  EXPECT_EQ(result, expected);
}

// Test 4: Check behavior with max_length = 1
TEST(FindAllPasswordsTest, MaxLengthOne) {
  std::unordered_set<std::string> valid_passwords = {"a", "b", "c"};
  std::unordered_set<std::string> dictionary = {"b"};

  BlackBox box(valid_passwords, dictionary);
  int max_length = 1;

  std::unordered_set<std::string> expected = {"a", "c"};  // "b" excluded
  auto result = FindAllPasswords(box, max_length);

  EXPECT_EQ(result, expected);
}