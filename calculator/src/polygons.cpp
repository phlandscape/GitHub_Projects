#include "../include/polygons.h"
#include <vector>

double perimeter_polygon(const std::vector<double>& vec)
{
 int sum = 0;
 for(auto it = vec.begin(); it != vec.end();)
 {
   sum += *it++;
 }
 return sum;
}// end of d perimeter_polygon(c&vec)
