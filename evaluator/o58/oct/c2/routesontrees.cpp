#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5+5, inf = 2e9+1;

int n, m, k, d[6][MAXN];
bool is[MAXN];
vector<P> g[MAXN];

struct data{
	int lv, u, w;
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
};

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
 		if(w < 0 && w >= -100) w = 0;
 		g[u].emplace_back(v, w);
	}
	fill_n(*d, 6*MAXN, inf);
	priority_queue<data> Q;
	d[0][1] = 0;
	Q.push({0, 1, 0});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.lv][now.u] != now.w) continue;
		int u = now.u;
		if(u == n) return !printf("%d\n", now.w);
		for(auto x:g[u]) {
			int v = x.x, w = x.y, lv = now.lv;
			if(w < 0 && lv == k) continue;
			if(w < 0) lv++, w = 0;
			if(d[lv][v] > d[now.lv][u] + w) {
				d[lv][v] = d[now.lv][u] + w;
				Q.push({lv, v, d[lv][v]});
			}
		}
	}
	return !printf("-1\n");
}