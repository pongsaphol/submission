#include <bits/stdc++.h>
#define long long long
#define pl pair<long, int>
#define x first
#define y second
using namespace std;

const int N = 4e4+5;

int n, m;
long dp[105][N], qs[N], INF = 1e18;

void solve(int i, int l, int r, int x, int y) {
	if(l > r) return;
	int m = (l + r) >> 1;
	dp[i][m] = INF;
	int best = -1;
	for(int k = x; k <= min(y, m-1); ++k) {
		long v = dp[i-1][k] + (m-k)*(qs[m]-qs[k]);
		if(dp[i][m] > v) dp[i][m] = v, best = k;
	}
	solve(i, l, m-1, x, best);
	solve(i, m+1, r, best, y);
}

int main() {
	if(m > n-1) m = n-1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", qs+i), qs[i] += qs[i-1];
	for(int i = 1; i <= n; ++i) dp[0][i] = i*qs[i];
	for(int i = 1; i <= m; ++i) solve(i, 1, n, 1, n);
	printf("%lld\n", dp[m][n]);
}