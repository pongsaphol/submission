#include <cstdio>
#include <algorithm>
#include <vector>
#define long long long
using namespace std;

long dp[35];

int main() {
	// freopen("r", "r", stdin);
	long x, y;
	scanf("%lld%lld", &x, &y);
	dp[0] = 1ll;
	for(int i = 1; i <= 32; ++i) dp[i] = dp[i-1] * 2;
	long sum = 0;
	for(int i = 0; i <= 32; ++i) {
		long z = (y + dp[i]);
		z /= (long)dp[i];
		z--;
		sum += z;
	}
	printf("%lld\n", sum);
}
/*
000  0
001  1
010  2
011  3
100  4
*/
