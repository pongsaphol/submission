#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#define pii pair<int, int>
#define x first
#define y second
using namespace __gnu_pbds;
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
vector<vector<int> > g(N);
ordered_set<pii> S1[N], S2[N];
int n, m, ptr, dp[N], H[N], dep[N], d[N][18];
bool chk[N];

inline int find(int u, int p, int sz, pii &ret) {
	int mx = 0; dp[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) {
		dp[u] += find(v, u, sz, ret);
		mx = max(mx, dp[v]);
	}
	mx = max(mx, sz - dp[u]);
	if(ret.x > mx) ret = pii(mx, u);
	return dp[u];
}

inline void maked(int u, int p, int i) {
	for(auto v : g[u]) if(v != p and !chk[v]) d[v][i] = d[u][i] + 1, maked(v, u, i);
}

inline void solve(int u, int p, int sz) {
	pii ret(sz, -1);
	find(u, 0, sz, ret);
	H[u = ret.y] = p, dep[u] = dep[p] + 1, chk[u] = true;
	maked(u, 0, dep[u]);
	for(auto v : g[u]) if(!chk[v]) solve(v, u, dp[v] < dp[u] ? dp[v] : sz - dp[u]);
}

inline void fastscan(int &ret) {
	ret = 0;
	for(register int c = getchar(); c >= '0' and c <= '9'; c = getchar()) ret = (ret<<1) + (ret<<3) + c - '0';
}

int main() {
	fastscan(n), fastscan(m);
	for(int i = 1, u, v; i < n; ++i) {
		fastscan(u), fastscan(v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	solve(1, 0, n);
	while(m--) {
		int met, a, b = 0; fastscan(met), fastscan(a);
		if(met == 1) {
			fastscan(b);
			S1[a].insert(pii(b, ++ptr));
			for(int i = H[a], pv = a; i; i = H[i], pv = H[pv]) if(b - d[a][dep[i]] >= 0) 
				S1[i].insert(pii(b - d[a][dep[i]], ++ptr)), S2[pv].insert(pii(b - d[a][dep[i]], ++ptr));
		} else {
			auto val = [&](ordered_set<pii> &S, int d) { return S.size() - S.order_of_key(pii(d, 0)); };
			b += val(S1[a], 0); 
			for(int i = H[a], pv = a; i; i = H[i], pv = H[pv]) b += val(S1[i], d[a][dep[i]]) - val(S2[pv], d[a][dep[i]]);
			printf("%d\n", b); 
		}
	}	
}