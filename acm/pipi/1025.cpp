#include<iostream>
#include<cmath>
using namespace std;

double minOfX2(double a, double b, double c, int x1, int y1, int x2, int y2) {
	// f(x) = ax2 + bx + c
	double x = - b / (2 * a);
	if(x >= 0)
		return a * x * x + b * x + c;
//	return min(a * x1 * x1 + b * x1 + c, a * x2 * x2 + b * x2 + c);
	return x1 * x1 + x2 * x2 - 2 * x1 * x2 + y1 * y1 + y2 * y2 - 2 * y1 * y2;
}

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++) {
		int x1, y1, x2, y2;
		int vx1, vy1, vx2, vy2;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> vx1 >> vy1 >> vx2 >> vy2;

		printf("Case %d: %.6f\n", i + 1, sqrt(minOfX2((vx2 - vx1) * (vx2 - vx1) + (vy2 - vy1) * (vy2 - vy1),
		                              2 * ((x2 - x1) * (vx2 - vx1) + (y2 - y1) * (vy2 - vy1)),
		                              (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 -y1), x1, y1, x2, y2)));
	}
}
