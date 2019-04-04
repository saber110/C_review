#include<iostream>
#define MAX 11
#define BLANK '.'
#define TRAP '*'
#define U 0
#define R 1
#define D 2
#define L 3
#define ALLDIRECTIONS 4
using namespace std;

bool mark[MAX][MAX];
int ans = 1;
int w, h;
// up	right	down	left
//const int go[][2] = {0,-1, 1,0, 0,1, -1,0};
const int go[][2] = {-1,0, 0,1, 1,0, 0,-1};
char data[MAX][MAX];

bool valid(int x, int y) {
	if(x >= 0 && x < w && y >= 0 && y < h && mark[x][y] == false && data[x][y] == BLANK) {
		return true;
	}
	return false;
}

int DirNext(int dir) {
	// out of border
	// trap
	return (dir + 1) % ALLDIRECTIONS;
}

void DFS(int x, int y, int dir) {
//		cout << "x:\t" << x << "\ty:\t" << y << "\tdir:\t" << dir <<endl;
		int nx = x + go[dir][0];
		int ny = y + go[dir][1];
		int count = 0;
		while(!valid(nx, ny)) {
			
			dir = DirNext(dir);
			nx = x + go[dir][0];
			ny = y + go[dir][1];
//			cout << "nx:\t" << nx << "\tny:\t" << ny << "\tdir:\t" << dir << "\tcount\t" << count << endl;
			if(count++ >= 1)
				return ;
		}
		mark[nx][ny] = true;
		DFS(nx, ny, dir);
		ans ++;
//		mark[nx][ny] = false;
}

int main() {

	while(cin >> w >> h) {
		int sx, sy;
		ans = 1;
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++) {
				mark[i][j] = false;
				data[i][j] = 0;
			}

		for(int i = 0; i < w; i ++)
			for(int j = 0; j < h; j ++) {
				cin >> data[i][j];
				if(data[i][j] != TRAP && data[i][j] != BLANK) {
					sx = i;
					sy = j;
				}
			}
		
//		cout << "start: " << data[sx][sy] << endl;
//		cout << "sx:\t" << sx << "\tsy:\t" << sy << endl;
		switch(data[sx][sy]){
			case 'U': DFS(sx, sy, U);break;
			case 'R': DFS(sx, sy, R);break;
			case 'D': DFS(sx, sy, D);break;
			case 'L': DFS(sx, sy, L);break;
		}
		cout << ans << endl;
	}
	return 0;
}
