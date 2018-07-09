#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
#define long long long
using namespace std;

const int MAXN = 35;

long d[MAXN][MAXN][1<<4], inf = 1e18;
int X[] = {0, 0, 1, -1}, Y[] = {-1, 1, 0, 0};
int n, m, A[MAXN][MAXN], comp[MAXN][MAXN];
bool chk[MAXN][MAXN];

bool go(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void flood(int x, int y, int val) {
	queue<P> Q;
	Q.emplace(x, y);
	comp[x][y] = val;
	while(!Q.empty()) {
		auto now = Q.front();
		Q.pop();
		for(int i = 0; i < 4; ++i) {
			int x = now.x + X[i], y = now.y + Y[i];
			if(go(x, y) && !A[x][y] && comp[x][y] == -2) {
				comp[x][y] = val;
				Q.emplace(x, y);
			}
			if(go(x, y) && A[x][y]) if(val == -1) chk[x][y] = true;
		}
	}
}

long mn = inf;
int cnt = 0, sx, sy;

void dfs(int xc, int yc, int bitc) {
	if((1<<cnt) - 1 == bitc) {
		mn = min(mn, d[xc][yc][bitc]);
		return;
	}
	for(int i = 0; i < 4; ++i) {
		int x = xc + X[i], y = yc + Y[i], bit = bitc;
		if(!go(x, y) || chk[x][y]) continue;
		if(comp[x][y] >= 0) bit |= (1 << comp[x][y]);
		if(d[x][y][bit] > d[xc][yc][bitc] + A[x][y]) {
			d[x][y][bit] = d[xc][yc][bitc] + A[x][y];
			int old = A[x][y];
			A[x][y] = 0;
			dfs(x, y, bit);
			A[x][y] = old;
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		scanf("%d", &A[i][j]);
		comp[i][j] = -2;
	}
	for(int i = 1; i <= n; ++i) {
		if(!A[i][1] && comp[i][1] == -2) flood(i, 1, -1);
		if(!A[i][m] && comp[i][m] == -2) flood(i, m, -1);
	}
	for(int i = 1; i <= m; ++i) {
		if(!A[1][i] && comp[1][i] == -2) flood(1, i, -1);
		if(!A[n][i] && comp[n][i] == -2) flood(n, i, -1);
	}
	fill(d[0][0], d[31][31] + (1<<4), inf);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(!A[i][j] && comp[i][j] == -2) {
			if(!cnt) sx = i, sy = j;
			flood(i, j, cnt++);
		}
	}
	d[sx][sy][1] = 0;
	dfs(sx, sy, 1);
	printf("%lld\n", mn);
}