#include "../include/triangle.h"
#include <vector>
#include <cmath>
inline double perimeter_triangle(double a, double b, double c)
{ // rewrite with ellipses? c++11 hint: variadic templates
  return a+b+c;
}// end of perimeter_triangle (d,d,d)

double area_triangle(double a, double b, double c)
{
  double s = perimeter_triangle(a,b,c) / 2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}// end of area_triangle (d,d,d)

double area_triangle(double b, double h)
{
  return b*h*0.5;
}// end of area_triangle (d,d)
