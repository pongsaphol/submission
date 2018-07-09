#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using vi = vector<int>;
using vivi = pair<vi, vi>;
const int N = 1e4+5, INF = 1e9;

int n, m, dp[N][32];
vector<vivi> V[N];

bool calc(int start, vivi &now) {
	bool st = false;
	for(auto x : now.x) st |= !(start & (1 << x));
	for(auto x : now.y) st |= start & (1 << x);
	return st;
}

int solve(int start) {
	for(int i = 0; i < 32; ++i) {
		dp[1][i] = 0;
		if(i != start) dp[1][i] = -INF;
		else for(auto &x : V[1]) dp[1][i] += calc(start, x);
	}
	for(int i = 2; i <= n; ++i) for(int j = 0; j < 32; ++j) {
		int ret = j; if(ret & (1 << 4)) ret ^= (1 << 4);
		dp[i][j] = max(dp[i-1][ret<<1], dp[i-1][ret<<1|1]);
		for(auto &x : V[i]) dp[i][j] += calc(j, x);
	}
	if(start & (1 << 4)) start ^= (1 << 4);
	return max(dp[n][start << 1], dp[n][start << 1 | 1]);
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int e, f, l; scanf("%d %d %d", &e, &f, &l);
		vi F, L;
		while(f--) {
			int ret; scanf("%d", &ret);
			if(e > 5 and ret <= 5) ret += n; 
			F.emplace_back(ret - e);
		}
		while(l--) {
			int ret; scanf("%d", &ret);
			if(e > 5 and ret <= 5) ret += n;
			L.emplace_back(ret - e);
		}
		V[e].emplace_back(F, L);
	}
	int mx = 0;
	for(int i = 0; i < 32; ++i) mx = max(mx, solve(i));
	printf("%d\n", mx);
}