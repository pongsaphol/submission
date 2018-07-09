#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct data {
	int d, p, x, y;
	data(int d, int p, int x, int y) : d(d), p(p), x(x), y(y) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.d > b.d;
	}
};

int X[] = {0, 1, -1}, Y[] = {1, 0, 0};
int n, m, s;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &s);
	vector<vector<bool> > A(n+2, vector<bool>(m+2, 0));
	vector<vector<vector<int> > > d(3, vector<vector<int> >(n+1, vector<int>(m+1, inf)));
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		char ret; scanf(" %c", &ret);
		A[i][j] = (ret == '.');
	}
	d[0][s][1] = 0;
	priority_queue<data> Q;
	Q.emplace(d[0][s][1], 0, s, 1);
	int cnt = 0;
	while(!Q.empty()) {
		++cnt;
		auto u = Q.top(); Q.pop();
		if(d[u.p][u.x][u.y] != u.d) continue;
		if(u.y == m) return !printf("%d\n", u.d);
		for(int i = 0; i < 3; ++i) {
			int x = u.x + X[i], y = u.y + Y[i], w = (i != u.p ? 1 : 0);
			if(A[x][y] and d[i][x][y] > u.d + w) {
				d[i][x][y] = u.d + w;
				Q.emplace(d[i][x][y], i, x, y);
			}
		}
	}
	puts("-1");
}