#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100005][3], mod = 2009;

int f(int x) {
	if(x < 0) return 100001;
	return x;
}

int main() {
	// freopen("r", "r", stdin);
	dp[0][2] = 1;
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 3; ++j) {
			int p = (j+2)%3;
			dp[i][j] = (dp[i-1][p] + dp[f(i-2)][p] - dp[f(i-k-1)][p]) % mod;
			dp[i-1][p] = (dp[i-1][p] + dp[f(i-2)][p]) % mod;
			// printf("%d ", dp[i][j]);
		}
		// printf("\n");
	}

	int ans = 0;
	for(int i = 0; i < 3; ++i) ans += dp[n][i];
	printf("%d\n", ((ans%mod)+mod)%mod);
}