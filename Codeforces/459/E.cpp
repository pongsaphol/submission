#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

struct edge {
	int u, v, w;
	friend inline bool operator<(const edge &a, const edge &b) {
		return a.w < b.w;
	}
};

const int MAXN = 3e5+5;

int n, m, dp[MAXN], tmp[MAXN];
vector<P> g[MAXN];

int main() {
	red();
	vector<edge> E;
	cin >> n >> m;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[w].emplace_back(u, v);
	}
	for(int i = 0; i < MAXN; ++i) {
		for(auto x:g[i]) tmp[x.y] = 0;
		for(auto x:g[i]) tmp[x.y] = max(tmp[x.y], dp[x.x] + 1);
		for(auto x:g[i]) dp[x.y] = max(dp[x.y], tmp[x.y]);
	}
	return !printf("%d\n", *max_element(dp+1, dp+n+1));
}