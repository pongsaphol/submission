#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;

int n, m, dp[MAXN][MAXN];
bool is[MAXN][MAXN];
char A[MAXN];


int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A);
	n = strlen(A);
	for(int i = 0; i < n; ++i) {
		is[i][i] = true;
		is[i+1][i] = true;
		dp[i][i] = 1;
	}
	for(int len = 2; len <= n; ++len) 
	for(int i = 0; i <= n - len; ++i) {
		is[i][i+len-1] = is[i+1][i+len-2] & (A[i] == A[i+len-1]);
		dp[i][i+len-1] = dp[i][i+len-2] + dp[i+1][i+len-1] - dp[i+1][i+len-2] + is[i][i+len-1];
	}
	scanf("%d", &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		printf("%d\n", dp[a][b]);
	}
}