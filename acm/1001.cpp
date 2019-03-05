#include <iostream>
#include <iomanip>

using namespace std;

float Roundedto(float num){
    float result;
    if(num >= 0){
        if((num * 10000 - (num * 10000)/1) >= 0.5){
            result = num + 0.0001;
        }
        else result = num;
    }
    else{
        if((num * 10000 - (num * 10000)/1) <= -0.5){
            result = num - 0.0001;
        }
        else result = num;
    }
    return result;
}
int main(){
    float a , b;
    while(cin >> a >> b){
        cout << fixed << setprecision(4) << Roundedto(a + b)<< endl;
    }
    return 0;
}
