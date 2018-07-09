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

const int MAXN = 2005;

vector<P> E;
vector<int> g[MAXN];
int n, H[MAXN], A[MAXN][MAXN], dep[MAXN], anc[MAXN][15];
long d[MAXN];

int find(int u) {
	if(H[u] == u) return u;
	return H[u] = find(H[u]);
}

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	anc[u][0] = p;
	for(int i = 1; i <= 10; ++i) anc[u][i] = anc[anc[u][i-1]][i-1];
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		d[v] = d[u] + A[u][v];
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 10; i >= 0; --i) 
		if(dep[anc[a][i]] >= dep[b]) a = anc[a][i];
	if(a == b) return a;
	for(int i = 10; i >= 0; --i) {
		if(anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

void kill() {
	puts("NO");
	exit(0);
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &A[i][j]);
	for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) {
		H[i] = i;
		if(i == j) {
			if(A[i][j] != 0) kill();
			continue;
		}
		if(A[i][j] != A[j][i] || A[i][j] == 0) kill();
		E.emplace_back(i, j);
	}
	sort(all(E), [&](const P &a, const P &b) { return A[a.x][a.y] < A[b.x][b.y]; });
	for(auto x:E) {
		int a = find(x.x), b = find(x.y);
		if(a != b) {
			H[a] = b;
			g[x.x].emplace_back(x.y);
			g[x.y].emplace_back(x.x);
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) {
		if(A[i][j] != d[i] + d[j] - (d[lca(i, j)]<<1)) {
			if(n == 1139) cout << "bug LCA" << endl;
			kill();
		}
	}
	puts("YES");
}