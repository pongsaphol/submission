#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int n, m, k, dp[MAXN][MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		++dp[++a][++b];
	}
	for(int i = 1; i <= m; ++i) for(int j = 1; j <= m; ++j) {
		dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
	}
	int mn = 1e9;
	for(int i = 0; i < m; ++i) for(int j = i + 1; j <= m; ++j) {
		// I will binary search eieiei
		int l = 1, r = m;
		while(l < r) {
			int m = (l + r) >> 1;
			if(dp[m][j] - dp[m][i] >= k) r = m;
			else l = m + 1;
		}
		if(dp[r][j] - dp[r][i] >= k) mn = min(mn, (j - i) * r);
	}
	printf("%d\n", mn);
}