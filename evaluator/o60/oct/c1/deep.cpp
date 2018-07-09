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

const int MAXN = 2e5+5;

int n, m, level[MAXN], anc[18][MAXN];
P g[MAXN];

void dfs(int x, int lv) {
	level[x] = lv;
	if(g[x].x == -1 && g[x].y == -1) {
		for(int i = 0; i <= 17; ++i) anc[i][x] = x;
		return;
	}
	if(g[x].x != -1 && g[x].y != -1) {
		for(int i = 0; i <= 17; ++i) anc[i][x] = x;
		level[x] = lv+1;
		dfs(g[x].x, lv+1);
		dfs(g[x].y, lv+1);
		return;
	}
	int now;
	if(g[x].x == -1) now = g[x].y;
	else now = g[x].x;
	dfs(now, lv);
	anc[0][x] = now;
	for(int i = 1; i <= 17; ++i) anc[i][x] = anc[i-1][anc[i-1][x]];
}

int L, s, a, b;
int dir() {
	int res = ((s&8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}

int solve(int lv, int v) {
	// printf("%d %d\n", lv, v);
	if(lv == 0) return v;
	if(level[anc[0][v]] != level[v]) {
		lv--;
		v = anc[0][v];
	}
	while(g[v].x != -1 && g[v].y != -1) {
		if(lv == 0) return v;
		bool st = dir();
		lv--;
		if(st) v = g[v].y;
		else v = g[v].x;
	}
	for(int i = 17; i >= 0; --i) {
		if(lv - (1<<i) < 0) continue;
		if(level[anc[i][v]] != level[v]) continue;
		v = anc[i][v];
		lv -= (1<<i);
	}
	return solve(lv, v);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	for(int i = 0; i < n; ++i) {
		int a = input(), b = input();
		g[i] = {a, b};
	}
	dfs(0, 1);
	while(m--) {
		L = input(), s = input(), a = input(), b = input();
		printf("%d\n", solve(L, 0));
	}
}