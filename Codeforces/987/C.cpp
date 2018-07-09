#include <bits/stdc++.h>
using namespace std;
const int N = 3e3+5;
int dp[N][3], S[N], C[N];

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", S+i);
	for(int i = 1; i <= n; ++i) scanf("%d", C+i);
	for(int i = 1; i <= n; ++i) dp[i][1] = C[i];
	for(int i = 1; i <= n; ++i) for(int j = 2; j <= 3; ++j) {
		dp[i][j] = 1e9;
		for(int k = 1; k < i; ++k) if(S[k] < S[i]) {
			dp[i][j] = min(dp[i][j], dp[k][j-1] + C[i]);
		}
	}
	int mn = 1e9;
	for(int i = 1; i <= n; ++i) mn = min(mn, dp[i][3]);
	if(mn == (int)1e9) return !printf("-1");
	printf("%d\n", mn);
}