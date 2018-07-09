#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, dp[N][N][2];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		int now; scanf("%d", &now);
		while(now % 2 == 0) dp[i][j][0]++, now /= 2;
		while(now % 3 == 0) dp[i][j][1]++, now /= 3;
		for(int k = 0; k < 2; ++k) dp[i][j][k] += dp[i-1][j][k] > dp[i][j-1][k] ? dp[i-1][j][k] : dp[i][j-1][k];
	}
	printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
}