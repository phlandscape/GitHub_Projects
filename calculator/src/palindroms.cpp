#include <vector>
#include <string>
#include <sstream>
#include <iostream>
bool is_palindrome(const std::string& s)
{//
  auto it = s.begin();
  auto ed = s.begin()+s.size()-1;
  while(it!=ed)
  {
    if(*it++ != *ed--)
    {
      return false;
    }
  }
  return true;
}// end of b is_palindrome(str)
bool is_palindrome(int n)
{
/* same as
  std::ostringstream convert;
  convert << n;
  std::string temp = convert.str();
  if(is_palindrome(temp))*/
 return is_palindrome(std::string(static_cast<std::ostringstream*>( &(std::ostringstream() << n) )->str()));
}// end of b is_palindrome (i)

std::vector<std::vector<int> > AllPalin_InRange(int lower, int higher)
{
 std::vector<std::vector<int> > all;
 std::vector<int> numbers;
 int palin = 0;
 for(int i = lower; i < higher;i++)
 {
  for(int bb = lower+1; bb < higher; bb++)
  {
    if(palin < i*bb)
    {
      if( is_palindrome(i*bb))
      {
       palin = i*bb;
       numbers.clear();
       numbers.push_back(palin);
       numbers.push_back(i);
       numbers.push_back(bb);
       all.push_back(numbers);
      }
   }
  }
 }
 return all;
}// end of vec<vec<i> > AllPalin_InRange(i,i)

std::vector<int> HighestPalin_InRange(int lower, int higher)
{
 std::vector<int> numbers;
 int palin = 0;
 int a = lower;
 int b = lower;
 for(int i = lower; i < higher;i++)
 {
  for(int bb = i; bb < higher; bb++)
  {
    if(palin < i*bb)
    {
      /* same as
      std::ostringstream convert;
      convert << i*bb;
      if(is_palindrome(std::string(convert.str())))*/
      if( is_palindrome(std::string(static_cast<std::ostringstream*>( &(std::ostringstream() << (i*bb)) )->str())))
      {
       palin = i*bb;
       a = i;
       b = bb;
      }
    }
  }
 }
 if(palin != 0)
 {
  numbers.push_back(palin);
  numbers.push_back(a);
  numbers.push_back(b);
 }
  return numbers;
}// end of vec<i> HighestPalin_InRange(i,i)

void PrintVec(const std::vector<int>& v)
{
 for(auto it = v.begin(); it != v.end(); it++)
 {
   std::cout << *it << "  ";
 }
 std::cout << std::endl;
}// end of v PrintVec(vec<i>)
