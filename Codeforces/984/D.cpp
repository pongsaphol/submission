#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

int n, A[N][N], dp[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A[i]+i);
	for(int len = 1; len < n; ++len) for(int i = 1; i + len <= n; ++i) 
		A[i][i+len] = A[i][i+len-1] ^ A[i+1][i+len];
	for(int len = 0; len < n; ++len) for(int i = 1; i + len <= n; ++i) {
		dp[i][i+len] = max({A[i][i+len], dp[i][i+len-1], dp[i+1][i+len]});
	}
	int q; scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
}