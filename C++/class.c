#include <iostream>
#include "class.h"
using namespace std;

void Example::test()
{
  cout << "hh " << x << " "<< y << endl;
}

Example::Example()
{
  x = 5;
  y = 0;
}
Example::Example(int a, int b)
{
    x = a;
    y = b;
}

Example::~Example()
{
  x = 0;
}
