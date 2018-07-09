#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e3;

int n, m, dp[4][MAXN+5][MAXN+5];
char arr[MAXN+5][MAXN+5];

int solve() {
	memset(dp, 0, sizeof dp);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", arr[i]+1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(arr[i][j] == '1') {
				dp[0][i][j] = dp[0][i][j-1] + 1;
				dp[2][i][j] = dp[2][i-1][j] + 1;
			}
		}
	}
	for(int i = n; i >= 1; --i) {
		for(int j = m; j >= 1; --j) {
			if(arr[i][j] == '1') {
				dp[1][i][j] = dp[1][i][j+1] + 1;
				dp[3][i][j] = dp[3][i+1][j] + 1;
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			mx = max(mx, max(dp[0][i][j], dp[1][i][j]) + max(dp[2][i][j], dp[3][i][j]) - 1);
		}
	}
	return mx;
}

int main() {
	// freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) printf("%d\n", solve());
}