#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 3e4+5;

int n, anc[MAXN][16], level[MAXN];
vector<int> g[MAXN];

void dfs(int x, int p = 0, int lv = 1) {
	anc[x][0] = p;
	level[x] = lv;
	for(int i = 1; i < 16; ++i) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for(auto v:g[x]) if(v != p) dfs(v, x, lv + 1);
}

int lca(int a, int b) {
	if(level[a] < level[b]) swap(a, b);
	for(int i = 15; i >= 0; --i) {
		if(level[anc[a][i]] >= level[b]) a = anc[a][i];
	}
	if(a == b) return a;
	for(int i = 15; i >= 0; --i) {
		if(anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 1; i < n; ++i) {
		int u = input(), v = input();
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0, 1);
	int T = input(), x = 1, sum = 0;
	while(T--) {
		int y = input();
		sum += level[x] + level[y] - 2*level[lca(x, y)];
		swap(x, y);
	}
	return !printf("%d\n", sum);
}