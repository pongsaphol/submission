#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n;
vector<pii> V;

pii findm(int i, int j) {
	pii m(V[i].y - V[0].y, V[i].x - V[0].x);
	if(m.x != 0 and m.y != 0) {
		int gcd = __gcd(m.x, m.y);
		m.x /= gcd, m.y /= gcd;
	}
	if(m.x == 0) m.y = 1;
	if(m.y == 0) m.x = 1;
	if(m.y < 0) m.x *= -1, m.y *= -1;
	return m;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		V.emplace_back(a, b);
	}
	map<pii, vector<int> > M;
	for(int i = 1; i < n; ++i) M[findm(i, 0)].emplace_back(i);
	for(auto x : M) {
		
	}

}