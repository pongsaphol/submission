#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e5 + 5;

int n;
long A[MAXN], qs[MAXN], ep[MAXN], sum[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", A + i);
	for(int i = 1; i <= n; ++i) scanf("%lld", qs + i), qs[i] += qs[i-1];
	for(int i = 1; i <= n; ++i) {
		int l = i, r = n;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(qs[m] - qs[i-1] <= A[i]) l = m;
			else r = m-1;
		}
		if(qs[l] - qs[i-1] > A[i]) l--;
		// printf("%d %d\n", i, l);
		ep[i]++, ep[l+1]--;
		sum[l+1] += A[i] - (qs[l] - qs[i-1]);
	}
	for(int i = 1; i <= n; ++i) {
		ep[i] += ep[i-1];
		sum[i] += ep[i] * (qs[i] - qs[i-1]);
		printf("%lld ", sum[i]);
	}

}