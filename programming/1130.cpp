#include <cstdio>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 1e4, mod = 49999;

long dp[2][MAXN+5];

int main() {
	// freopen("r", "r", stdin);
	dp[0][1] = -1;
	dp[0][2] = 1;
	int n;
	scanf("%d", &n);
	for(int i = 3; i <= n; ++i) {
		int a = i-1, b = 0;
		for(int j = 1; j <= i; ++j) {
			dp[i&1][j] = dp[(i-1)&1][j]*a + dp[(i-1)&1][j-1]*b;
			dp[i&1][j] %= mod;
			a--, b++;
		}
	}
	long sum = 0;
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		sum += dp[n&1][i] * now;
		sum %= mod;
	}
	printf("%lld\n", (sum+mod)%mod);
}