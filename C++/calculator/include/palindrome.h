#ifndef PALINDROME_H_INCLUDED
#define PALINDROME_H_INCLUDED

#include <string>
#include <vector>
/* a short library for palindromes in numbers and strings
 *
*/

bool is_palindrome(int n);
bool is_palindrome(const std::string& s);
std::vector<std::vector<int> > AllPalin_InRange(int lower, int higher);
std::vector<int> HighestPalin_InRange(int lower, int higher);
void PrintVec(const std::vector<int>& v);

#endif // PALINDROME_H_INCLUDED
