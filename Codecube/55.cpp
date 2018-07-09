#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int main() {
	//freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	dp[1][1] = 1;
	for(int i = 2; i <= 1000; ++i) {
		for(int j = 1; j <= i; ++j) {
			dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
			dp[i][j] %= 9871;
		}
	}
	while(T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}