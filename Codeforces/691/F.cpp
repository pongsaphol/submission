#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 3e6;

int n, m, freq[N+5];
long dp[N+5];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	dp[1] = ((long)n*(n-1));
	while(n--) {
		int ret; scanf("%d", &ret);
		freq[ret]++;
	}
	for(long i = 1; i <= N; ++i) for(long j = i; j <= N; j += i) {
		if(j % i == 0) {
			if(i*i == j) dp[j+1] -= (freq[i]*(freq[i]-1));
			else dp[j+1] -= ((long)freq[i]*freq[j/i]);
		}
	}
	for(int i = 2; i <= N; ++i) dp[i] += dp[i-1];
	scanf("%d", &m);
	while(m--) {
		int ret; scanf("%d", &ret);
		printf("%lld\n", dp[ret]);
	}
}