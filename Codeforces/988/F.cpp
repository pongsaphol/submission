#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e5+5, inf = 1e9;

int a, m, n, dp[N];
bool rain[N];

int main() {
	scanf("%d %d %d", &a, &m, &n);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		for(++a; a <= b; ++a) rain[a] = true;
	}
	vector<pii> u;
	while(n--) {
		int a, b; scanf("%d %d", &a, &b);
		u.emplace_back(a, b);
	}
	fill(dp, dp + N, inf);
	dp[0] = 0;
	for(int i = 1; i <= a; ++i) {
		if(!rain[i]) {
			dp[i] = dp[i-1];
			continue;
		}
		for(auto x : u) if(x.x < i) {
			dp[i] = min(dp[i], dp[x.x] + (i - x.x) * x.y);
		}
	}
	if(dp[a] == inf) return !printf("-1");
	printf("%d\n", dp[a]);
}