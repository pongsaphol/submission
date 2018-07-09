#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 55;

int n, m;
long ans, A[N];
bool dp[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", A+i), A[i] += A[i-1];
	for(int lv = 60; ~lv; --lv) {
		memset(dp, 0, sizeof dp), dp[0][0] = 1;
		long ret = ans | (1ll << lv);
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) for(int k = 0; k < i; ++k) {
			if(((A[i] - A[k]) & ret) == ret) dp[i][j] |= dp[k][j-1];
		}
		if(dp[n][m]) ans = ret;
	}
	printf("%lld\n", ans);
}