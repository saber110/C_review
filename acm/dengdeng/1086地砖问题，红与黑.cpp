#include<iostream>
#define MAX 21
#define BLACK '.'
#define RED '#'
#define START '@'
#define ALLDIRECTIONS 4
using namespace std;

bool mark[MAX][MAX];
int ans = 1;
int w, h;
const int go[][2] = { 1,0,-1,0, 0,1, 0,-1};
char data[MAX][MAX];

bool valid(int x, int y) {
	if(x >= 0 && x < h && y >= 0 && y < w && mark[x][y] == false && data[x][y] == BLACK) {
		return true;
	}
	return false;
}

void DFS(int x, int y) {
	for(int i = 0; i < ALLDIRECTIONS; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(valid(nx, ny)) {
			mark[nx][ny] = true;
			DFS(nx, ny);
			ans ++;
//			mark[nx][ny] = false;
		}
	}
}

int main() {

	while(cin >> w >> h) {
		if(w == 0 && h == 0) return 0;
		int sx, sy;
		ans = 1;
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++) {
				mark[i][j] = false;
				data[i][j] = 0;
			}

		for(int j = 0; j < h; j ++)
			for(int i = 0; i < w; i ++) {
				cin >> data[j][i];
				if(data[j][i] == START) {
					sx = j;
					sy = i;
				}
			}

		DFS(sx, sy);
		cout << ans << endl;
	}
	return 0;
}
