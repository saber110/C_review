#include<iostream>
#include<string>
#define MAXL 101
using namespace std;

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		// the num of coincidence of s1[i] s2[j] 
		long long temp[MAXL][MAXL];
		for(int i = 1; i <= s1.length(); i ++){
//			temp[0][i] = 0;
//			temp[i][0] = 0;
			for(int j = 1; j <= s2.length(); j ++){
				if(s1[i-1] == s2[j-1])	temp[i][j] = temp[i-1][j-1] + 1; 
				else  temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
			}
		}
		cout << temp[s1.length()][s2.length()] << endl;
	}
}
