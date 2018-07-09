/*
TASK: o59_oct_c2_speedup
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define long long long
#define P pair<int, int> 
#define x first
#define y second
using namespace std;

const int MAXN = 8e4+5;

int n, m, l, q;
long d[10][MAXN], inf = 1e18;
vector<P> g[MAXN];
bool is[MAXN];

typedef struct data {
	long w;
	int u, lv, p;
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
} data;

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &l, &q);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w);
	}
	while(l--) {
		int x;
		scanf("%d", &x);
		is[x] = true;
	}
	fill_n(*d, 10*MAXN, inf);
	priority_queue<data> Q;
	d[0][1] = 0;
	Q.push({0, 1, 0, 0});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(now.u == n) return !printf("%lld\n", now.w);
		if(d[now.lv][now.u] != now.w) continue;
		int lv = now.lv, u = now.u, p = now.p;
		if(is[u] && lv != q && p != u) {
			lv++;
			p = u;
		}
		for(auto x:g[u]) {
			int v = x.x, w = x.y;
			if(d[lv][v] > now.w + (w >> lv)) {
				d[lv][v] = now.w + (w >> lv);
				Q.push({d[lv][v], v, lv, p});
			}
		}
	}
}