#include <iostream>
#include <queue>
#include <vector>
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

struct data{
	int v, w;
	bool st;
};

struct nq{
	int u, c, w;
	friend inline bool operator<(const nq &a, const nq &b) {
		return a.w > b.w;
	}
};

const int MAXN = 1e4+5, inf = 1e9;

int n, m, s, l, d[MAXN][55];
vector<data> g[MAXN];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> s >> l;
	while(m--) {
		int u = input(), v = input(), w = input();
		g[u].push_back({v, w, false});
	}
	while(s--) {
		int u = input(), v = input(), w = input();
		g[u].push_back({v, w, true});
	}
	priority_queue<nq> Q;
	Q.push({1, 0, 0});
	fill(d[0], d[MAXN-1] + 54, 1000000000);
	d[1][0] = 0;
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.u][now.c] != now.w) continue;
		int u = now.u, lv = now.c;
		for(auto x:g[u]) {
			bool st = x.st;
			int v = x.v, w = x.w;
			if(d[v][lv+st] > d[u][lv] + w) {
				d[v][lv+st] = d[u][lv] + w;
				Q.push({v, lv+st, d[v][lv+st]});
			}
		}
	}
	int mn = inf;
	for(int i = 0; i <= l; ++i) {
		mn = min(mn, d[n][i]);
	}
	printf("%d\n", mn);
}