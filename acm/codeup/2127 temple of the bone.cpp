#include<iostream>
#define MAXN 7
#define MAXM 7
#define START 'S'
#define DOOR 'D'
#define ALLDIRECTIONS 4
#define WALL 'X'
using namespace std;

int n, m, T, dx, dy;
bool flag = false;
bool visit[MAXN][MAXM] = {false};
//const int go[][2] = {0,1, 0,-1, 1,0, -1,0};
const int go[][2] = {1,0, -1,0, 0,1, 0,-1};
char data[MAXN][MAXM];

bool valid(int x, int y) {
	if(x >= 0 && x <= n && y >= 0 && y <= m && visit[x][y] == false && data[x][y] != WALL) {
//		cout << "valid:\t" << x << " : " << y << endl;
		return true;
	}
	return false;

//	if(x < 0 || x >= n || y < 0 || y >= m)
//		return false;
//	if(visit[x][y] == true || data[x][y] == WALL)
//		return false;
//	return true;
}

bool DFS(int x, int y, int t) {
	if(t > T)	return false;
	for(int i = 0; i < ALLDIRECTIONS; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];

		if(valid(nx, ny)) {
			visit[nx][ny] = true;

			if(data[nx][ny] == DOOR) {
				// && t == T -1
				cout << "YES\t"<< t <<  endl;
				flag = true;
//				return true;
			}
			DFS(nx, ny, t + 1);
			visit[nx][ny] == false;
		}
	}
}
int main() {
	while(cin >> n >> m >> T) {
		int sx, sy;
		// init
		flag = false;
		for(int i = 0; i < MAXN; i ++)
			for(int j = 0; j < MAXM; j ++) {
				visit[i][j] = false;
				data[i][j] = 0;
			}
		if(n == 0 && m == 0 && T == 0)	break;
		// input
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++) {
				cin >> data[i][j];
				if(data[i][j] == START) {
					sx = i;
					sy = j;
				} else if(data[i][j] == DOOR) {
					dx = i;
					dy = j;
				}
			}
//		cout << sx << '\t' << sy << '\t' << dx << '\t' << dy << '\t' << T <<endl;
		DFS(sx, sy, 0);
		if(flag == false)	cout << "NO" << endl;
	}
	return 0;
}
