#include<iostream>
#define BLANK '.'
#define TRAP '*'
#define ALLDIRECTIONS 4
#define MAX 101
using namespace std;

int m, n, t, k, sx, sy, ex, ey;
char data[MAX][MAX];
bool mark[MAX][MAX], flag;
const int go[][2] = {-1,0, 0,1, 1,0, 0,-1};
// suppose 90 degree every turn

bool valid(int x, int y) {
	if(x >= 0 && x < m && y >= 0 && y < n && mark[x][y] == false && data[x][y] == BLANK)
		return true;
	return false;
}
int dirNext(int dir) {
	return (dir + 1) % ALLDIRECTIONS;
}
bool DFS(int x, int y, int k, int curDir) {
	for(int i = 0; i < ALLDIRECTIONS; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(valid(nx, ny)) {
			if(i != curDir) k = k -1;
//			cout << "nx:\t" << nx << "\tny:\t" << ny << 
//			"\tcurDir\t" << curDir << "\tnextDir\t" << i 
//			<< "\tk\t" << k << endl;
			
			if(k < -1) {
//				cout << "faild" << endl;
				continue;
//				return false;
			}
			if(nx == ex && ny == ey) {
				cout << "yes" << endl;
				flag = true;
				return true;
			}
			mark[nx][ny] = true;
			DFS(nx, ny, k, i);
			mark[nx][ny] = false;
		}

	}
}
int main() {
	cin >> t;
	for(int i = 0; i < t; i ++) {
		cin >> m >> n;
		flag = false;
		for(int i = 0; i < MAX; i ++)
			for(int j = 0; j < MAX; j ++) {
				data[i][j] = 0;
				mark[i][j] = false;
			}
		for(int j = 0; j < m; j ++) {
			cin >> data[j];
		}
		cin >> k >> sy >> sx >> ey >> ex;
		sx --;
		sy --;
		ex --;
		ey --;
		for(int i = 0; i < ALLDIRECTIONS; i ++) {
//			cout << "once again\t" << i << endl;
			if(DFS(sx, sy, k, i)) break;
		}

		if(flag == false)	cout << "no" << endl;
	}
	return 0;
}
