#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, m, q, dpv[N][N], dph[N][N], dp[N][N], dpz[4][N][N];
int X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
bool A[N][N], chk[N][N];

void dfs(int x, int y, int &x1, int &y1, int &x2, int &y2) {
	chk[x][y] = true;
	x1 = min(x, x1), y1 = min(y, y1), x2 = max(x, x2), y2 = max(y, y2);
	for(int i = 0; i < 4; ++i) {
		int nx = x + X[i], ny = y + Y[i];
		if(!chk[nx][ny] and A[nx][ny]) dfs(nx, ny, x1, y1, x2, y2);
	}
}

int f(int x) {
	if(x < 0) return 302;
	return x;
}

int area(int c, int x1, int y1, int x2, int y2) {
	int ret = dpz[c][x2][y2] - dpz[c][f(x1-1)][y2] - dpz[c][x2][f(y1-1)] + dpz[c][f(x1-1)][f(y1-1)];
	return ret;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		scanf("%1d", A[i]+j);
		dph[i][j] = dph[i-1][j] + dph[i][j-1] - dph[i-1][j-1] + (A[i][j] != A[i-1][j]);
		dpv[i][j] = dpv[i-1][j] + dpv[i][j-1] - dpv[i-1][j-1] + (A[i][j] != A[i][j-1]);
		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (A[i][j] != A[i][j-1] || 
		A[i][j] != A[i-1][j] || A[i-1][j] != A[i-1][j-1] || A[i][j-1] != A[i-1][j-1]);
	}
	int cntcom = 0;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(A[i][j] and !chk[i][j]) {
		int x1 = 1e9, x2 = 0, y1 = 1e9, y2 = 0; cntcom++;
		dfs(i, j, x1, y1, x2, y2);
		x1--, y1--, x2++, y2++;
		dpz[0][x1][y1]++, dpz[1][x1][y2]++, dpz[2][x2][y1]++, dpz[3][x2][y2]++;
	}
	for(int k = 0; k < 4; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		dpz[k][i][j] += dpz[k][i-1][j] + dpz[k][i][j-1] - dpz[k][i-1][j-1];
	}
	// V-E+F = 2
	while(q--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int V = 0, E = 0;
		V += dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1];
		E += dpv[x2][y2] - dpv[x1-1][y2] - dpv[x2][y1] + dpv[x1-1][y1];
		E += dph[x2][y2] - dph[x1][y2] - dph[x2][y1-1] - dph[x1][y1-1];
		int ret = area(3, x2+1, 0, n, y2) + area(2, 0, 0, x2, y1-1)
				 + area(1, x1, y2+1, n, m) + area(0, 1, y1, x1-1, m);
		ret = cntcom - ret;
		printf("%d\n", 1 - V + E + ret);
	}
}