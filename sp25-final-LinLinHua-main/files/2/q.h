
#ifndef SOL_2_Q
#define SOL_2_Q

#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
In a movie theater, n students are to be seated in a single row. Each student is
from one of several countries, represented by integers where each integer
corresponds to a country. Write a program to print all possible seating
arrangements where no two students from the same country sit next to each other.

Input:

students: A list of integers where each integer represents the country of a
student.

Output:

Each arrangement should list the countries
in the order they appear in the row. Return an empty list if no valid
arrangement is possible.

Constraints:
The input list may contain multiple students from the same or different
countries.

Example 1:
students = {1, 2, 3}
Output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Explanation:
All students are from different countries, so any permutation of the list is a
valid seating arrangement.


Example 2:
Input:
students = {1, 1, 2, 3}
Output:
1 2 1 3
1 3 1 2
2 1 3 1
3 1 2 1
1 2 3 1
1 3 2 1
Explanation:
There are enough students from different countries to intersperse students from
the same country (1). Each valid arrangement ensures that no two '1's are
adjacent.


Example 3:
Input:
students = {1, 1, 2, 2}
Output:
1 2 1 2
2 1 2 1
Explanation:
The arrangement possibilities are limited but sufficient to meet the criteria.
Each country's students can alternate without repeating.


Example 4:
Input:
students = {1, 1, 1, 2}
Output:
Empty list


*/

std::vector<std::vector<int>>
MovieTheaterAssignment(const std::vector<int> &students);
#endif /* SOL_2_Q */
