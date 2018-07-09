#include <bits/stdc++.h>
#define long long long
using namespace std;

const long MAXN = 1e5 + 5;

long n, m, A[MAXN], B[MAXN], c0[MAXN], mod = 1e9 + 7;

long val(long a, long b) {
	long ret = 1;
	for(; b; b >>= 1) {
		if(b&1) {
			ret *= a;
			ret %= mod;
		}
		a *= a;
		a %= mod;
	}
	return ret;
}

long mul(long a, long b) {
	a %= mod, b %= mod;
	return (a*b) % mod;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", A + i);
	for(int i = 1; i <= n; ++i) scanf("%lld", B + i);
	for(int i = n; i != 0; --i) c0[i] = c0[i+1] + (int)(A[i] == 0) + (int)(B[i] == 0);
	long Q = val(val(m, c0[1]), mod-2);
	long P = 0, time = 1;
	for(long i = 1; i <= n; ++i) {
		if(A[i] > 0 && B[i] > 0) {
			if(A[i] != B[i]) {
				if(A[i] > B[i]) P += mul(time, val(m, c0[i]));
				break;
			}
			continue;
		}
		if(A[i]) P += mul(mul(time, (A[i] - 1)), val(m, c0[i+1]));
		else if(B[i]) P += mul(mul(time, (m - B[i])), val(m, c0[i+1]));
		else {
			P += mul(mul(time, (m-1)*(m)/2), val(m, c0[i+1]));
			time *= m;
			time %= mod;
		}
		P %= mod;
	}
	P %= mod;
	printf("%lld\n", (P*Q) % mod);
}