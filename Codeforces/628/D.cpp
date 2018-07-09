#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5, M = 1e9+7;

int n, m, d, dp[N][N];
char A[N], B[N];

int add(int a, int b) { return (a + b) % M; }

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &m, &d);
	scanf("%s %s", A+1, B+1);
	n = strlen(A+1) / 2;
	for(int i = 1; i <= n; ++i) for(int j = 0; j < m; ++j) {
		int R = A[(i << 1) - 1] - '0';
		if(A[i << 1] - '0' )
	}
}