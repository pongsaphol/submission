#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

int n, m, dp[MAXN+5][MAXN+5];

int main() {
	// freopen("r", "r", stdiwn);
	scanf("%d%d", &n, &m);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		// i will plus 1 to dp//
		dp[a+1][b+1]++;
	}

	for(int i = 1; i <= MAXN; ++i) {
		for(int j = 1; j <= MAXN; ++j) {
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	while(m--) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		// plus it
		x++, y++;
		int x1 = x-k, y1 = y-k, x2 = x+k, y2 = y+k;
		if(x1 < 1) x1 = 1;
		if(y1 < 1) y1 = 1;
		if(x2 > MAXN) x2 = MAXN;
		if(y2 > MAXN) y2 = MAXN;
		printf("%d\n", dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]);
	}
	return 0;
}