#ifndef CONVERTING_H_INCLUDED
#define CONVERTING_H_INCLUDED

#include <string>
#include <vector>
#include <cmath>
#include <sstream>
double to_decimal(double a, double point);
std::vector<int> GetHighestFirstVal(std::vector<std::vector<int> > s);
template<typename T>
void nums_from_string_to_vec(const std::string& str, std::vector<T>& vec)
{ /// NOT FINISHED // didn't review after "++it;"
  auto it = str.rbegin();
  while(it != str.rend()){
    int scaler = 0;
    int temp = 0;
    while(*it != ' ')
    {
        if(*it = ',')
        {
            temp /= pow(10,scaler);
        }
      temp += to_decimal(((*it - 49) > 0 && (*it - 49) < 9) ? (*it - 49): 0,scaler++);
      ++it;
    }
  }


}// end of nums_from_string_to_vec (str,vec)
std::vector<int> nums_from_string_to_vec(const std::string& str);

#endif // CONVERTING_H_INCLUDED
