#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;

const int MAXN = 2e4 + 5;

int n, m, s, t, d[MAXN], inf = 1e9;
vector<P> g[MAXN];

char* solve() {	
	for(int i = 0; i < MAXN; ++i) g[i].clear();
	scanf("%d %d %d %d", &n, &m, &s, &t);
	while(m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	fill(d, d + MAXN, inf);
	priority_queue<P, vector<P>, greater<P> > Q;
	d[s] = 0;
	Q.emplace(d[s], s);
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(now.y == t) {
			char ret[20];
			sprintf(ret, "%d", now.x);
			return ret;
		}
		if(d[now.y] != now.x) continue;
		for(auto v : g[now.y]) {
			if(d[v.x] > now.x + v.y) {
				d[v.x] = now.x + v.y;
				Q.emplace(d[v.x], v.x);
			}
		}
	}
	return "unreachable";
}	

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		printf("Case #%d: %d\n", T, solve());
	}
}