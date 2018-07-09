#include <bits/stdc++.h>
using namespace std;

int n, m, R[1005][55], C[55][1005], d[1005][55], lev[1005][55];
bool in[1005][55];

bool chk(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

struct data {
	int d, p, x, y;
	data(int d, int p, int x, int y) : d(d), p(p), x(x), y(y) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.d > b.d;
	}
};

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 1; j < m; ++j) scanf("%d", R[i] + j);
	for(int i = 1; i <= m; ++i) for(int j = 1; j < n; ++j) scanf("%d", C[i] + j);
	for(int i = 1; i <= n; ++i) {
		priority_queue<data> Q;
		Q.emplace(0, 0, i, 1);
		lev[i][1] = i, d[i][1] = 0, in[i][1] = false;
		while(!Q.empty()) {
			auto u = Q.top(); Q.pop();
			if(in[u.x][u.y]) continue;
			in[u.x][u.y] = true;
			if(u.p + abs(i-u.x) + abs(m - u.y) >= 200) continue;
			int x, y, w;
			x = u.x+1, y = u.y, w = C[u.y][u.x];
			if(chk(x, y)) {
				if(lev[x][y] != i) lev[x][y] = i, d[x][y] = 1000000, in[x][y] = false;
				if(d[x][y] > d[u.x][u.y] + w) {
					d[x][y] = d[u.x][u.y] + w;
					Q.emplace(d[x][y], u.p+1, x, y);
				}
			}
			x = u.x-1, y = u.y, w = C[u.y][u.x-1];
			if(chk(x, y)) {
				if(lev[x][y] != i) lev[x][y] = i, d[x][y] = 1000000, in[x][y] = false;
				if(d[x][y] > d[u.x][u.y] + w) {
					d[x][y] = d[u.x][u.y] + w;
					Q.emplace(d[x][y], u.p+1, x, y);
				}
			}
			x = u.x, y = u.y+1, w = R[u.x][u.y];
			if(chk(x, y)) {
				if(lev[x][y] != i) lev[x][y] = i, d[x][y] = 1000000, in[x][y] = false;
				if(d[x][y] > d[u.x][u.y] + w) {
					d[x][y] = d[u.x][u.y] + w;
					Q.emplace(d[x][y], u.p+1, x, y);
				}
			}
			x = u.x, y = u.y-1, w = R[u.x][u.y-1];
			if(chk(x, y)) {
				if(lev[x][y] != i) lev[x][y] = i, d[x][y] = 1000000, in[x][y] = false;
				if(d[x][y] > d[u.x][u.y] + w) {
					d[x][y] = d[u.x][u.y] + w;
					Q.emplace(d[x][y], u.p+1, x, y);
				}
			}
		}
		printf("%d\n", d[i][m]);
	}
}