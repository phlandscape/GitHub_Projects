
#include <iostream>

int GoThrough(int a);
int Doing(int n, int b);

int main()
{
    int n, b;
    while(std::cin >> n >> b)
    {
      std::cout << n << " " << b << " ";
      if(n<b)
      {
        std::cout << Doing(n,b) << std::endl;
      }
      else{
        std::cout << Doing(b,n) << std::endl;
      }
    }
    return 0;
}
int GoThrough(int a)
{
 int counting = 1;
 for(; a != 1;(a%2)?(a=3*a+1):(a/=2)){counting++;}
 return counting;
}

int Doing(int n, int b)
{
 int counting = 0;
 while(n <= b)
 {
  int temp = GoThrough(n++);
  if(counting < temp){counting = temp;}
 }
 return counting;
}
