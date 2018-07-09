#include <bits/stdc++.h>
using namespace std;
int f(int x) { return x*x; }
struct data {
	int x, y, r;
	data(int x, int y, int r) : x(x), y(y), r(r) { }
	friend inline bool operator<(const data &a, const data &b) { return a.x < b.x; }
	friend inline bool operator+(const data &a, const data &b) {
		int lhs = f(a.x-b.x) + f(a.y-b.y), rhs = f(a.r+b.r);
		return lhs < rhs;
	}
};

int n, cnt;
vector<data> V;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		V.emplace_back(a, b, c);
	}
	sort(V.begin(), V.end());
	for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j) {
		if(V[j].x - V[i].x > 20) break;
		if(V[i] + V[j]) cnt++;
	}
	printf("%d\n", cnt);
}