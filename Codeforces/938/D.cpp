#include <bits/stdc++.h>
#define long long long
#define P pair<long, int>
#define x first
#define y second
using namespace std;

const int MAXN = 2e5 + 5;

int n, m;
vector<P> g[MAXN];
long d[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	while(m--) {
		int u, v;
		long w;
		scanf("%d %d %lld", &u, &v, &w);
		g[u].emplace_back(w, v);
		g[v].emplace_back(w, u);
	}
	priority_queue<P, vector<P>, greater<P> > Q;
	for(int i = 1; i <= n; ++i) {
		long now;
		scanf("%lld", &now);
		d[i] = now;
		Q.emplace(now, i);
	}
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		int u = now.y;
		if(d[u] != now.x) continue;
		for(auto v : g[u]) {
			if(d[v.y] > d[u] + 2*v.x) {
				d[v.y] = d[u] + 2*v.x;
				Q.emplace(d[v.y], v.y);
			}
		}
	}
	for(int i = 1; i <= n; ++i) printf("%lld ", d[i]);
}