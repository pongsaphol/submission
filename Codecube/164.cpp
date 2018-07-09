#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 123460;

int n, delay = 0;
long ans = 1e18, pref[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", pref+i), pref[i] += pref[i-1];
	for(int i = 1; i <= n; ++i) {
		int idx = lower_bound(pref, pref + n, 2 * pref[i]) - pref;
		int l = max(i+1, idx - delay), r = min(n-1, idx + delay);
		for(int j = l; j <= r; ++j) {
			vector<long> V;
			V.emplace_back(pref[i]), V.emplace_back(pref[j]-pref[i]), V.emplace_back(pref[n]-pref[j]);
			sort(V.begin(), V.end());
			ans = min(ans, V.back() - V[0]);
		}
	}
	printf("%lld\n", ans);
}