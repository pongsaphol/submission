#include <cstdio>
#include <algorithm>
using namespace std;

int x, y, m, ans, dp[15];

int main() {
	// freopen("r", "r", stdin);
	dp[1] = 5;
	for(int i = 2; i <= 13; ++i) dp[i] = dp[i-1]*5;
	scanf("%d%d%d", &x, &y, &m);
	int prev = 0;
	for(int j = 1; j <= 13; ++j) {
		prev += x/dp[j];
		prev %= m;
	}
	ans += prev;
	for(int i = x + 1; i <= y; ++i) {
		for(int j = 1; j <= 13; ++j) {
			if(i%dp[j] != 0) break;
			prev++;
			prev %= m;
		}
		ans += prev;
		ans %= m;
	}
	printf("%d\n", ans);
}