#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

#include "calculator.h"
int main()
{
    std::vector<std::vector<int> > AllThreeDigitPalins = AllPalin_InRange(100,1000);
  for(auto it = AllThreeDigitPalins.begin(); it != AllThreeDigitPalins.end(); it++)
  {
    PrintVec(*it);
  }
  std::cout << std::endl;

}// end of main
