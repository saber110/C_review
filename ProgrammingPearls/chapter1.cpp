#include <iostream>
#include <bitset>
#include <fstream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 10000000
#define weiCount 7
using namespace std;

int main() {
  bitset<N> bitNum  (0);
  ifstream file("chapter1Data.txt");
  string PhoneNum;

  while (file >> PhoneNum) //以字符串方式读取，碰到回车结束一次
  {
    bitNum[atoi(PhoneNum.c_str()) - 1] = 1;
  }
  file.close();
  cout << "PhoneNum Counts " << bitNum.count() << endl;

  for(unsigned int i = N/10; i < N; i ++)
  {
    if(bitNum[i] == 1)
    {
      cout << i + 1 << endl;
    }
  }
  return 0;
}
