#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, q, dp[1005][1005];

int main() {
	// freopen("r", "r", stdin);
	dp[1][1] = 1;
	scanf("%d %d", &n, &q);
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		dp[a][b] = 1;
	}
	for(int i = 1; i <= 1000; ++i) for(int j = 1; j <= 1000; ++j) {
		if(i == 1 && j == 1) continue;
		if(dp[i][j]) dp[i][j] = 0;
		else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		dp[i][j] %= MOD;
	}
	while(q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
}
