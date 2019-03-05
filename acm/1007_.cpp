#include<iostream>
using namespace std;
int main() {
  int num, px,py, ax, ay, bx,by;
  cin >> num ;  // 输入总情况数
  for(int i = 0; i < num; i++){
    cin >> px >> py;
    cin >> ax >> ay >> bx >> by;
    cout << '\n' <<num << endl;
    cout << "px -- py  " << px << " -- " << py << endl;
    cout << "ax -- ay  " << ax << " -- " << ay << endl;
    cout << "bx -- by  " << bx << " -- " << by << endl;

    // 判断关系
    if(px < ax || px > bx || py < ay || py > by)
      cout << "Outside" << endl;
    else if(px > ax && px < bx && py < by && py > ay)
      cout << "Inside" << endl;
    else
      cout << "On" << endl;
  }
  std::cout << "hah" << '\n';
  return 0;
}
