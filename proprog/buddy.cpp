#include <cstdio>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 1<<10;

int dp[MAXN+5];

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int build = 0;
		char arr[20];
		scanf("%s", arr);
		for(i = 0; arr[i] != '\0'; ++i) {
			build |= (1<<(arr[i] - '0'));
		}
		ans += dp[build]++;
	}
	long ans = 0;
	for(int i = 1; i <= MAXN; ++i) {
		for(int j = i+1; j <= MAXN; ++j) {
			ans += (long)dp[i] * dp[j];
		}
	}
	printf("%lld\n", ans);
}