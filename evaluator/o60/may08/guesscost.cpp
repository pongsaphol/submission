#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, A[N], dp[N][N];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int len = 1; len <= n; ++len) {
		for(int i = 1, j = len; j <= n; ++i, ++j) {
			if(i == j) {
				dp[i][j] = A[i];
				continue;
			}
			dp[i][j] = 1e9;
			for(int k = i; k <= j; ++k) {
				dp[i][j] = min(dp[i][j], A[k] + max(dp[i][k-1], dp[k+1][j]));
			}
		}
	}
	printf("%d\n", dp[1][n]);
}