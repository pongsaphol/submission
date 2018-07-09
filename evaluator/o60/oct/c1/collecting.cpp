#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define long long long 
#define x first
#define y second
#define P pair<int, int>
using namespace std;

const int MAXN = 5e4+5, inf = 1e9;

int n, m, l, s, t, A[MAXN], d[35][MAXN];
vector<P> g[MAXN];

struct node {
	int w, lv, u;
	friend inline bool operator<(const node &a, const node &b) {
		return a.w > b.w;
	}
};

int main() {
	freopen("r", "r", stdin);
	scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w);
	}
	fill(d[0], d[31] + MAXN, inf);
	priority_queue<node> Q;
	d[0][s] = 0;
	Q.push({0, 0, s});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.lv][now.u] != now.w) continue;
		int u = now.u;
		if(u == t && now.lv == l) return !printf("%d\n", now.w);
		for(auto x:g[u]) {
			int v = x.x, w = x.y, lv = now.lv;
			if(now.lv == A[v]-1) lv++;
			if(d[lv][v] > d[now.lv][u] + w) {
				d[lv][v] = d[now.lv][u] + w;
				Q.push({d[lv][v], lv, v});
			} 
		}
	}
}