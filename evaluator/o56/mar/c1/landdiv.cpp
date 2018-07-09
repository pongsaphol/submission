#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, cnt, d[MAXN], dp[MAXN][MAXN], dep[MAXN][MAXN];

int range(int i, int j) { return d[j] - d[i-1]; }
void rec(int v, int i, int j) {
	if(i == 0 && j == 0) {
		dep[i][j] = v;
		dp[i][j] = 0;
	} else
	if(i == n+1 && j == 0) {
		dep[i][j] = v;
		dp[i][j] = 0;
	} else
	if(dep[i][j] != v) {
		dep[i][j] = v;
		dp[i][j] = 1e9;
	}
}
void solve1(int x, int val, int lv) { 
	for(int k = 1; k <= m; ++k) {
		for(int i = 1; i <= x; ++i) {
			for(int j = 1; j <= i; ++j) {
				if(range(j, i) < val) break;
				rec(lv, i, k), rec(lv, j-1, k-1);
				dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], range(j, i)));
			}
		}
	}
}

void solve2(int x, int val, int lv) {
	for(int k = 1; k <= m; ++k) {
		for(int i = n; i >= x; --i) {
			for(int j = n; j >= i; --j) {
				if(range(i, j) < val) break;
				rec(lv, i, k), rec(lv, j+1, k-1);
				dp[i][k] = min(dp[i][k], max(dp[j+1][k-1], range(i, j)));
			}
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	int mn = 1e9;
	for(int i = 1; i <= n; ++i) scanf("%d", &d[i]), d[i] += d[i-1];
	m--;
	if(m == 0) mn = 0;
	else for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) {
		if(i == 1 and j == n) continue;
		++cnt;
		int val = d[j] - d[i-1];
		solve1(i-1, val, cnt), solve2(j+1, val, cnt);
		for(int k = 0; k <= m; ++k) {
			rec(cnt, i-1, k), rec(cnt, j+1, m-k);
			int ret = max(dp[i-1][k], dp[j+1][m-k]) - val;
			mn = min(mn, ret);
		}
	}
	printf("%d\n", mn);
}