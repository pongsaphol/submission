#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <queue>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5 + 5;

int n, m, color[MAXN];
vector<int> g[MAXN];

bool check(int x) {
	bool is = true;
	color[x] = 1;
	queue<int> Q;
	Q.push(x);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(auto v:g[u]) {
			if(!color[v]) {
				color[v] = 3 - color[u];
				Q.push(v);
			}
			if(color[v] == color[u]) is = false;
		}
	}
	return is;
}

void init() {
	n = m = 0;
	for(int i = 0; i < MAXN; ++i) g[i].clear();
	memset(color, 0, sizeof color);
}

void solve() {
	init();
	n = input(), m = input();
	while(m--) {
		int u = input(), v = input();
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	bool is = true;
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) is &= check(i);
	}
	if(is) printf("yes\n");
	else printf("no\n");
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int T = input();
	while(T--) solve();
	return 0;
}