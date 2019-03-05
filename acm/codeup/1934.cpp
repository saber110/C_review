#include <iostream>
using namespace std;
#define MAXN 200
int main(int argc, char const *argv[]) {
  int n;
  while (cin >> n) {
    int data[MAXN] = {0}, x, result = -1;
    for (int i = 0; i < n; i++) {
      cin >> data[i];
    }
    cin >> x;

    for(int i = 0; i < n; i++){
      if(x == data[i]) result = i;
    }
    cout << result << endl;
  }
  return 0;
}
