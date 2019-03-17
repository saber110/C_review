#include<iostream>
#define MAXCROSSNUM 110
#define MAXROANUM 10010
#define STORE 1 
// if ox7fffffff then OVERFLOW
#define INF 0x3fffffff
using namespace std;

int main(){
	int crossNum, roadNum;
	while(cin >> crossNum >> roadNum){
		if(crossNum == 0 && roadNum == 0)	break;
		int map[MAXCROSSNUM][MAXCROSSNUM];
		// init
		for(int i = 1; i <= crossNum; i ++){
			for(int j = 1; j <= crossNum; j ++){
				map[i][j] = INF;
			}
			map[i][i] = 0;
		}
			
				
		// input
		// remember to chose the minimum of the same road
		for(int i = 0; i < roadNum; i ++){
			int a, b, c;
			cin >> a >> b >> c;
			map[a][b] = c;
			map[b][a] = c;		
		}
		// FLOYD
		for(int k = 1; k <= crossNum; k ++)
			for(int i = 1; i <= crossNum; i ++)
				for(int j = 1; j <= crossNum; j ++){
					if( map[i][k] + map[k][j] < map[i][j])
						map[i][j] = map[i][k] + map[k][j];
				}
		cout << map[STORE][crossNum] << endl;
	}
}
