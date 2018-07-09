#include <cstdio>
#define long long long
long dp[70][70][3];


void build() {
	dp[0][0][0] = 1;
	for(int i = 1; i <= 65; ++i) {
		for(int j = 0; j <= 65; ++j) {
			if(j > 0) dp[i][j][0] = dp[i-1][j-1][0] + dp[i-1][j-1][2]; // locking
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2]; // unlock
			dp[i][j][2] = dp[i-1][j][1]; // first lock
		}
	}
}

int main() {
	freopen("r", "r", stdin);
	freopen("w", "w", stdout);
	int n, m;
	build();
	bool st = false;
	while(scanf("%d%d", &n, &m)) {
		if(n < 0) break;
		printf("%lld\n", dp[n][m][0] + dp[n][m][1] + dp[n][m][2]);
	}
}