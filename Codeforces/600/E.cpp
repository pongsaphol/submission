#include <bits/stdc++.h>
#define long long long
#define x first
#define y second
using namespace std;

using pii = pair<long, int>;
using mii = map<int, int>;
using pim = pair<pii, mii>;

const int N = 1e5+5;

int n, A[N];
long ans[N];
vector<int> g[N];

pim dfs(int u, int p) {
	pim ret;
	ret.y[A[u]]++, ret.x.x = A[u], ret.x.y = 1;
	for(auto v : g[u]) if(v != p) {
		pim now = dfs(v, u);
		if(now.y.size() > ret.y.size()) swap(now, ret);
		for(auto &x : now.y) {
			ret.y[x.x] += x.y;
			if(ret.x.y < ret.y[x.x]) ret.x.y = ret.y[x.x], ret.x.x = 0;
			if(ret.x.y == ret.y[x.x]) ret.x.x += x.x;			
		}
	}
	ans[u] = ret.x.x;
	return ret;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
}