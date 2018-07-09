#include <bits/stdc++.h>
#define long long long
#define P pair<int, int>
#define Pl pair<long, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

long d[MAXN], inf = 1e18;
int n, m, pv[MAXN];
set<P> g[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == b) continue;
		auto it = g[a].lower_bound({b, 0});
		if(it->x != b) g[a].emplace(b, c);
		else if(it->y > c) {
			g[a].erase(it);
			g[a].emplace(b, c);
		}
		it = g[b].lower_bound({a, 0});
		if(it->x != a) g[b].emplace(a, c);	
		else if(it->y > c) {
			g[b].erase(it);
			g[b].emplace(a, c);
		} 
	}
	priority_queue<Pl, vector<Pl>, greater<Pl> > Q;
	fill(d, d + MAXN, inf);
	d[1] = 0;
	Q.emplace(d[1], 1);
	while(!Q.empty()) {
		auto now = Q.top(); Q.pop();
		if(now.x != d[now.y]) continue;

		for(auto v : g[now.y]) {
			if(d[v.x] > now.x + v.y) {
				d[v.x] = now.x + v.y;
				pv[v.x] = now.y;
				Q.emplace(d[v.x], v.x);
			}
		}
	}
	if(pv[n] == 0) return !printf("-1\n");
	stack<int> S;
	int now = n;
	while(now != 0) {
		S.emplace(now);
		now = pv[now];
	}
	while(!S.empty()) {
		printf("%d ", S.top());
		S.pop();
	}
	return !printf("\n");
}