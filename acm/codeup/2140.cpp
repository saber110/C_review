#include<iostream>
#define MAXM 110
#define MAXN 110
#define ALLDIRECTIONS 8
using namespace std;

int m, n, allYES, no, ans, markNum;
char matrix[MAXM][MAXN];
bool mark[MAXM][MAXN];
const int go[][2] = {1,0, -1,0, 0,1, 0,-1, 1,1, 1,-1, -1,1, -1,-1};
void DFS(int x, int y) {
	for(int i = 0; i < ALLDIRECTIONS; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		// check
		if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if(matrix[nx][ny] == '@') {
				if(!mark[nx][ny]) {
					mark[nx][ny] = true;
					markNum ++;
					DFS(nx,ny);
				}
			}
		}
	}
}
int main() {
	while(cin >> m >> n) {
		if(m == 0) break;
		for(int i = 0; i < MAXM; i ++)
			for(int j = 0; j < MAXN; j ++) {
				mark[i][j] = false;
				matrix[i][j] = 0;
			}
		markNum = 0;
		allYES = 0;
		no = 0;
		ans = 0;
		for(int i = 0; i < m; i ++)
			for(int j = 0; j < n; j ++) {
				cin >> matrix[i][j];
				if(matrix[i][j] != '*')
					allYES ++;
			}

		for(int i = 0; i < m; i ++)
			for(int j = 0; j < n; j ++) {
				if(!mark[i][j] && matrix[i][j] == '@') {
					DFS(i, j);
					ans ++;

				}

			}
		cout << ans << endl;

	}

	return 0;
}

