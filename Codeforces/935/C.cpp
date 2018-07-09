#include <bits/stdc++.h>
using namespace std;

double f(double x) {
	return x * x;
} 

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	double r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 == y2) {
		double d = r/2;
		printf("%.9f %.9f %.9f\n", x1 + d, y1, d);
		return 0;
	}
	double k = sqrt(f(x1-x2) + f(y1-y2));
	if(k > r) {
		printf("%.9f %.9f %.9f\n", x1, y1, r);
		return 0;
	}
	double d = (r + k) / 2;
	double xa = x2 + d*(x1 - x2) / k;
	double ya = y2 + d*(y1 - y2) / k;
	printf("%.9f %.9f %.9f\n", xa, ya, d);
}