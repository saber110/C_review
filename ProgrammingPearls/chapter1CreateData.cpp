#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#define N 1000000
#define NMax 9999999
#define weiCount 7
using namespace std;

int main()
{
  unsigned int i = 0;
  ofstream outf;
  outf.open("shapter1Data.txt");

  while(i < N)
  {
    unsigned int a = rand() % (NMax) + N;
    if(a >= N && a <= NMax)
    {
      outf << a << endl;
      i++;
    }
  }
  return 0;
}
