#include<iostream>
#define MAX 91
using namespace std;

long long opt[MAX];

long long dp_stairs(int n){
	opt[0] = 1;
	opt[1] = 2;
	for(int i = 2; i <= n; i ++){
		opt[i] = opt[i - 1] + opt[i - 2] ;
	}
	return opt[n - 1];
}
int main(){
	int n;
	while(cin >> n){
		cout << dp_stairs(n) << endl;
	}
	return 0;
} 
