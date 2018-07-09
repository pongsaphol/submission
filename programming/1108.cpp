#include <bits/stdc++.h>
#define long long long
using namespace std;


int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", qs+i), qs[i] += qs[i-1];
	fill (t, t + N, -INF); upd(0, 0);
	for(int i = 1; i <= n; ++i) {
		upd(i, dp[i-1] - qs[i]);
		int l = 0, r = i;
		while(l < r) {
			int m = (l + r) >> 1;
			if(qs[i] - qs[m] <= k) r = m;
			else l = m + 1;
		}
		dp[i] = qs[i] + que(r, i);
	}
	printf("%lld\n", dp[n]);
}