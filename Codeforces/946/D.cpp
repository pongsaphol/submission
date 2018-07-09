#include <bits/stdc++.h>
using namespace std;

int n, m, p;
char A[505][505];
int qs[505][505];
int mnf[505][505], mxz[505];
int dp[505][505];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	fill(mnf[0], mnf[504] + 504, 100000000);
	fill(dp[0], dp[504] + 504, 100000000);
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		A[i][j] -= '0';
		qs[i][j] = qs[i][j-1] + A[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = qs[i][m]; j <= p; ++j) mnf[i][j] = 0;
		for(int j = 1; j <= m; ++j) {
			if(A[i][j]) for(int k = j; k <= m; ++k) if(A[i][k]) {
				int sz = k-j+1;
				int use = qs[i][m] - qs[i][k] + qs[i][j-1];
				mnf[i][use] = min(mnf[i][use], sz);
				mxz[i] = max(mxz[i], sz);
			}
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= p; ++j) {
			for(int k = 0; k <= j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i-1][k] + mnf[i][j-k]);
			}
		}
	}
	printf("%d\n", dp[n][p]);
}	