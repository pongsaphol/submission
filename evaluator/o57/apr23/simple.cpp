#include <bits/stdc++.h>
#define long long long
using namespace std;

const long M = 1e9+7;

long dp[60][60];

long cnr(long n, long r) {
	if(n == r) return dp[n][r] = 1;
	if(r == 0) return dp[n][r] = 1;
	if(dp[n][r]) return dp[n][r];
	return dp[n][r] = (cnr(n-1, r) + cnr(n-1, r-1))%M;
}

long mul(long a, long b) { return ((a*b)%M + M) % M; }

long powll(long n, long p) {
	long ret = 1;
	n %= M;
	for(; p; p >>= 1) {
		if(p&1) ret = mul(ret, n);
		n = mul(n, n);
	}
	return ret;
}

long inv(long a) { return powll(a, M-2); }

long beta(long m, long x) {
	long all = 0;
	for(long n = 0; n <= m; ++n) {
		long ret = inv(n+1);
		long sum = 0;
		for(int k = 0; k <= n; ++k) {
			long in = (k%2 ? -1 : 1);
			in *= cnr(n, k);
			in = mul(in, powll(x+k, m));
			sum = (in+sum) % M;
		} 
		ret = mul(ret, sum);
		all = (all + ret) % M;
	}
	return all;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	long n, k;
	scanf("%lld %lld", &n, &k);
	long sum = 0;
	for(long p = 1; p <= k; ++p) {
		long ret = p;
		ret = mul(ret, (beta(p+1, n+1) - beta(p+1, 0) + M)% M); 
		ret = mul(ret, inv(p+1));
		sum = (sum + ret) % M;
	}
	printf("%lld\n", sum);
}