#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, dp[MAXN][400], A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	int rn = sqrt(n);
	for(int i = n; i >= 1; --i) {
		for(int j = 0; j <= rn; ++j) {
			if(i + A[i] + j > n) dp[i][j] = 1;
			else dp[i][j] = dp[i + A[i] + j][j] + 1;
		}
	}
	int T;
	scanf("%d", &T);
	while(T--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(y <= rn) {
			printf("%d\n", dp[x][y]);
			continue;
		}
		int sum = 0;
		while(x <= n) {
			sum++;
			x += A[x] + y;
		}
		printf("%d\n", sum);
	}
}