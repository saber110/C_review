#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 50
#define WALL 1
using namespace std;
typedef struct Status {
	int x, y, z, t, wall;		// pos and time to this pos
} status;

void printTemp(status temp){
//	cout << "x: " << temp.x << " y: " << temp.y << " z: " << temp.z << " w: " << temp.wall << endl; 
}
bool operator == (status s1, status s2) {
	return s1.wall == s2.wall && s1.y == s2.y && s1.z == s2.z && s1.x == s2.x;
}

bool valid(vector<status> data, int x0, int y0, int z0, int x, int y, int z) {
	// check sample
	status temp;
	temp.x = x0;
	temp.y = y0;
	temp.z = z0;
	temp.wall = WALL;

	vector<status>::iterator it = find(data.begin(), data.end(), temp);
	// there is not wall
	if(it == data.end()) {
		if(x0 <= x && x0 >= 0 && y0 <= y && y0 >= 0 && z0 <= z && z0 >= 0)
			return true;
	}

//	cout << "not valid" << endl;
	return false;
}

status trans(int wall, int x, int y, int z, int t) {
	status temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.t = t;
	temp.wall = wall;
	printTemp(temp);
	return temp;
}

int BFS(vector<status> data, int x, int y, int z, int time) {
	queue<status> s;
	bool mark[MAX][MAX][MAX];
	for(int i = 0; i < MAX; i ++)
			for(int j = 0; j < MAX; j ++)
				for(int u = 0; u < MAX; u ++) 
					mark[i][j][u] = false; 
	status temp;
	temp.x = temp.y = temp.z = temp.t = temp.wall = 0;
//	mark[temp.x][temp.y][temp.z] = true;
	s.push(temp);
	while(!s.empty()) {
		status q = s.front();
		
		s.pop();
		// skip used samples
		if(mark[q.x][q.y][q.z] == true || q.t > time) continue;
		mark[q.x][q.y][q.z] = true;
		// reach
		if(q.x == x && q.y == y && q.z == z) {
			return q.t;
		}
		printTemp(q);
		if(valid(data, q.x + 1, q.y, q.z, x, y, z)) {
			temp = trans(q.wall, q.x + 1, q.y, q.z, q.t + 1);
			s.push(temp);
		}
		if(valid(data, q.x - 1, q.y, q.z, x, y, z)) {
			temp = trans(q.wall, q.x - 1, q.y, q.z, q.t + 1);
			s.push(temp);
		}
		if(valid(data, q.x, q.y + 1, q.z, x, y, z)) {
			temp = trans(q.wall, q.x, q.y + 1, q.z, q.t + 1);
			s.push(temp);
		}
		if(valid(data, q.x, q.y - 1, q.z, x, y, z)) {
			temp = trans(q.wall, q.x, q.y - 1, q.z, q.t + 1);
			s.push(temp);
		}
		if(valid(data, q.x, q.y, q.z + 1, x, y, z)) {
			temp = trans(q.wall, q.x, q.y, q.z + 1, q.t + 1);
			s.push(temp);
		}
		if(valid(data, q.x, q.y, q.z - 1, x, y, z)) {
			temp = trans(q.wall, q.x, q.y, q.z - 1, q.t + 1);
			s.push(temp);
		}
	}
	return -1;
}

int main() {
	int testNum;
	cin >> testNum;
	while(testNum --) {
		vector<status> data;
		int A, B, C, T;
		cin >> A >> B >> C >> T;
		status temp;
		// input
		for(int i = 0; i < A; i ++)
			for(int j = 0; j < B; j ++)
				for(int u = 0; u < C; u ++) {
					cin >> temp.wall;
					temp.x = i;
					temp.y = j;
					temp.z = u;
					temp.t = 0;
					data.push_back(temp);
				}
		cout << BFS(data, A - 1, B - 1, C - 1, T) << endl;
	}
	return 0;
}
