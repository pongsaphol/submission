#include <bits/stdc++.h>
using namespace std;

int X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
int n, m, x1, _y1, x2, y2, d[32][32][32][32], dis[32][32][32][32], inf = 1e9;
char A[35][35];

struct data {
	int d, x1, _y1, x2, y2;
	data(int a, int b, int c, int _d, int e) {d = a, x1 = b, _y1 = c, x2 = _d, y2 = e; }
};

int a1 = inf, a2;

void chk(data z) {
	int now = dis[z.x1][z._y1][z.x2][z.y2];
	if(now < a1) {
		a1 = now;
		a2 = z.d;
	}
}

void findd() {
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		queue<pair<int, int> > Q;
		dis[i][j][i][j] = 0;
		Q.emplace(i, j);
		while(!Q.empty()) {
			auto now = Q.front();
			Q.pop();
			for(int k = 0; k < 4; ++k) {
				int x = now.first + X[k], y = now.second + Y[k];
				if(A[x][y] != '.') continue;
				if(dis[i][j][x][y] > dis[i][j][now.first][now.second] + 1) {
					dis[i][j][x][y] = dis[i][j][now.first][now.second] + 1;
					Q.emplace(x, y);
				}
			}
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(A[i][j] == 'A') x1 = i, _y1 = j, A[i][j] = '.';
		if(A[i][j] == 'B') x2 = i, y2 = j, A[i][j] = '.';
	}
	fill(d[0][0][0], d[30][30][30] + 31, inf);
	fill(dis[0][0][0], dis[30][30][30] + 31, inf);
	findd();
	queue<data> Q;
	d[x1][_y1][x2][y2] = 0;
	Q.emplace(d[x1][_y1][x2][y2], x1, _y1, x2, y2);
	while(!Q.empty()) {
		auto z = Q.front();
		Q.pop(); chk(z);
		for(int i = 0; i < 4; ++i) {
			x1 = z.x1 + X[i], _y1 = z._y1 + Y[i];
			x2 = z.x2 + X[i^1], y2 = z.y2 + Y[i^1];
			if(A[x1][_y1] != '.') x1 = z.x1, _y1 = z._y1;
			if(A[x2][y2] != '.') x2 = z.x2, y2 = z.y2;
			if(d[x1][_y1][x2][y2] > z.d + 1) {
				d[x1][_y1][x2][y2] = z.d + 1;
				Q.emplace(d[x1][_y1][x2][y2], x1, _y1, x2, y2);
			}
		}
	}
	if(a1 != inf) return !printf("%d %d\n", a1, a2);
	return !printf("-1 0\n");
}
