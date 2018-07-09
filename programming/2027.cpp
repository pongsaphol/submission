#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1505;

int p, arr[MAXN][MAXN], qs[MAXN][MAXN];
int dpl[MAXN][MAXN][4], dpr[MAXN][MAXN][4];

int sz(int x, int y) {
	return qs[x][y] - qs[x-p][y] - qs[x][y-p] + qs[x-p][y-p];
}

int solve(int n, int m) {
	memset(dpl, 0, sizeof dpl);
	memset(dpr, 0, sizeof dpr);
	for(int i = p; i <= n; ++i) 
	for(int j = p; j <= m; ++j) 
	for(int k = 1; k <= 3; ++k) {
		dpl[i][j][k] = max(dpl[i-p][m][k-1], dpl[i][j-p][k-1]) + sz(i, j);
		dpl[i][j][k] = max(dpl[i][j][k], max(dpl[i-1][j][k], dpl[i][j-1][k]));	
	}
	return dpl[n][m][3];
}

int main() {
	// freopen("r", "r", stdin);
	int n, m;
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &arr[i][j]);
			qs[i][j] = arr[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
	int mx = 0;
	mx = max(mx, solve(n, m));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			qs[i][j] = arr[n-i+1][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
	mx = max(mx, solve(n, m));
	swap(n, m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			qs[i][j] = arr[j][i] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
	mx = max(mx, solve(n, m));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			qs[i][j] = arr[j][n-i+1] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
	mx = max(mx, solve(n, m));
	printf("%d\n", mx);
}