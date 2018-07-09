#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

const int MAXN = 1e5+5;

int n, m, c[MAXN], ans[MAXN];
vector<int> g[MAXN];
vector<P> Q[MAXN];
map<int, int> cnt[MAXN], freq[MAXN];

void dfs(int u, int p) {
	cnt[u][c[u]] = 1;
	freq[u][1] = 1;
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		if(cnt[u].size() < cnt[v].size()) {
			swap(cnt[u], cnt[v]);
			swap(freq[u], freq[v]);
		}
		for(auto &x:cnt[v]) while(x.y--) ++freq[u][++cnt[u][x.x]];
		cnt[v] = freq[v] = {};
	}
	for(auto& x:Q[u]) ans[x.y] = freq[u][x.x];
}

int main() {
	red();
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", c+i);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		Q[a].emplace_back(b, i);
	}
	dfs(1, 1);
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}