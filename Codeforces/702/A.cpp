#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN], dp[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		dp[i] = (A[i] > A[i-1] ? dp[i-1] : 0) + 1;
	}
	printf("%d\n", *max_element(dp, dp+MAXN));
}