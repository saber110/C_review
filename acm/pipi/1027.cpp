#include<iostream>
#include<queue>
#define BLANK '.'
#define TRAP '*'
#define ALLDIRECTIONS 4
#define MAX 101
#define ALL -1
using namespace std;

typedef struct Point {
	int i, j, dir;
} point;
point temp;
int m, n, t, k, sx, sy, ex, ey;
char data[MAX][MAX];
bool mark[MAX][MAX], flag;
const int go[][2] = {1,0, -1,0, 0,-1, 0,1};
//const int go[][2] = {0,-1,-1,0, 0,1, 1,0};
queue<point> q;
// suppose 90 degree every turn

bool valid(int x, int y) {
	if(x >= 0 && x < m && y >= 0 && y < n && data[x][y] == BLANK)
		return true;
	return false;
}

void BFS(int x, int y, int k) {
	// mark initiated
	temp.i = x;
	temp.j = y;
	temp.dir = ALL;
	q.push(temp);
	mark[x][y] = true;
	while(!q.empty()) {
		temp = q.front();
		q.pop();

		if(temp.i == ex && temp.j == ey && temp.dir <= k) {
			flag = true;
			cout << "yes" << endl;
			return ;
		}
		for(int i = 0; i < ALLDIRECTIONS; i ++) {
			int nx = temp.i + go[i][0];
			int ny = temp.j + go[i][1];
			int dir = temp.dir;
			while(valid(nx , ny)) {
				if(mark[nx][ny] == false) {
					mark[nx][ny] = true;
					temp.i = nx;
					temp.j = ny;
					temp.dir = dir + 1;
					q.push(temp);
				}
				
				// zou wan yige fangxiang
				nx = nx + go[i][0];
				ny = ny + go[i][1];
			}
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
		while(!q.empty())	q.pop(); //注意要初始化
		for(int j = 0; j < m; j ++) {
			cin >> data[j];
		}
		cin >> k >> sy >> sx >> ey >> ex;
		sx --;
		sy --;
		ex --;
		ey --;

		BFS(sx, sy, k);
		if(flag == false)	cout << "no" << endl;
	}
	return 0;
}
