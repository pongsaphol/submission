#include <bits/stdc++.h>
#define P pair<double, double>
using namespace std;

struct data {
	double x, y, r;
};

data A[4];

double p2(double x) {
	return x*x;
} 

int d(data a, data b) {
	return sqrt(p2(a.x - b.x) + p2(a.y - b.y));
}

bool cut(data a, data b) {
	return p2(a.r + b.r) > p2(a.x-b.x) + p2(a.y - b.y);
}

bool in(data a, data b) {
	return (d(a, b) <= max(a.r, b.r)) && !cut(a, b);
}

int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	if(n == 1) return !printf("2");
	for(int i = 1; i <= n; ++i) {
		double x, y, p;
		scanf("%lf %lf %lf", &x, &y, &p);
		A[i] = {x, y, p};
	}
	if(n == 2) {
		if(cut(A[1], A[2])) return !printf("4");
		return !printf("3"); 
	}
	if(cut(A[1], A[2]) and cut(A[1], A[3]), cut(A[2], A[3])) return !printf("8");
	if((cut(A[1], A[2]) and cut(A[1], A[3])) or (cut(A[1], A[2]) and cut(A[2], A[3])) or(cut(A[1], A[3]) and cut(A[2], A[3]))) return !printf("6");
	if(in(A[1], A[2]) && in(A[1], A[3])) return !printf("4");
	if(in(A[1], A[2]) && cut(A[3], A[1]) && cut(A[3], A[2])) return !printf("7");
	if(in(A[2], A[3]) && cut(A[1], A[2]) && cut(A[3], A[1])) return !printf("7");
	if(in(A[3], A[1]) && cut(A[2], A[1]) && cut(A[3], A[2])) return !printf("7");
	if(in(A[1], A[2]) || in(A[3], A[2]) || in(A[1], A[3])) return !printf("5");
	return !printf("4");
}