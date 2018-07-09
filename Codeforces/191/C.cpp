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

int n, m, par[MAXN][18], dep[MAXN], ans[MAXN], dp[MAXN];
vector<int> g[MAXN];
map<P, int> M;

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	for(int i = 1; i <= 17; ++i) 
		par[u][i] = par[par[u][i-1]][i-1];
	for(auto v:g[u]) if(v != p) dfs(v, u);
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 17; i >= 0; --i) 
		if(dep[par[a][i]] >= dep[b]) a = par[a][i];
	if(a == b) return a;
	for(int i = 17; i >= 0; --i) {
		if(par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int mic(int u, int p) {
	int sum = dp[u];
	for(auto v:g[u]) if(v != p) {
		int now = mic(v, u);
		ans[M[{u, v}]] = now;
		sum += now;
	}
	return sum;
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		M[{a, b}] = i;
		M[{b, a}] = i;
	}
	dfs(1, 0);
	scanf("%d", &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		dp[a]++, dp[b]++, dp[lca(a, b)] -= 2;
	}
	mic(1, 0);
	for(int i = 1; i < n; ++i) printf("%d ", ans[i]);
}