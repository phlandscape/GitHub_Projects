#include "../include/converting.h"

double to_decimal(double a, double point)
{
  if(point > 0)
  {
    return a*pow(10,point);
  }else
  { // for negative exponents
   return 1/(a*pow(10,point));
  }
}// end of to_decimal (d,d)

std::vector<int> GetHighestFirstVal(std::vector<std::vector<int> > s)
{
 std::vector<int> ret;
 ret.push_back(0);
 auto temp = ret.begin();
 for(auto it = s.begin(); it != s.end(); it++)
 {
  if(*((*it).begin()) > *temp )
  {
    ret = *it;
    temp = ret.begin();
  }
 }
 return ret;
}// end of vec<i> GetHighestFirstVal(c&vec<vec<i> >)

std::vector<int> nums_from_string_to_vec(const std::string& str)
{
  std::vector<int> ret;
  auto it = str.begin();
  while(it != str.end())
  {
    // skip any non number sign
    while(*it <= 48 && *it >= 57)
    {
      it++;
      if(it == str.end())
      {
        return ret;
      }
    }
    std::string temp;
    auto longing = it;
    while(*longing >= 48 && *longing <= 57 && longing != str.end())
    {
      temp += *longing++;
    }
    std::istringstream turnme(temp);
    int m = 0;
    turnme >> m;
    ret.push_back(m);
  }
  return ret;
}// end of vec<i> nums_from_string_to_vec(c&str)
