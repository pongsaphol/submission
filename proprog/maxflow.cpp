#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int inf = 1e9;

int n, m, s, t, mt[105][105], idx;
vector<int> g[105];
vector<P> now;
bool chk[105];
int mn, mid;

void init() {
	memset(mt, 0, sizeof mt);
	for(int i = 0; i < 105; ++i) g[i].clear();
	mn = inf;
	mid = 0;
}

bool dfs(int u) {
	if(u == t) return true;
	chk[u] = true;
	for(auto v:g[u]) {
		if(mt[u][v] < mid || chk[v]) continue;
		if(dfs(v)) {
			now.emplace_back(u, v);
			mn = min(mn, mt[u][v]);
			return true;
		} 
	}
	return false;

}

int main() {
	red();
	while(scanf("%d", &n), n) {
 		scanf("%d%d%d", &s, &t, &m);
 		init();
 		while(m--) {
 			int u, v, w;
 			scanf("%d%d%d", &u, &v, &w);
 			mt[u][v] += w;
 			mt[v][u] += w;
 			mid = max(mid, mt[u][v]);
 			g[u].emplace_back(v);
 			g[v].emplace_back(u);
 		}
 		int sum = 0;
 		while(mid >= 1) {
 			while(dfs(s)) {
	 			for(auto E:now) mt[E.x][E.y] -= mn, mt[E.y][E.x] += mn;
	 			sum += mn;
	 			now.clear();
	 			mn = inf;
	 			memset(chk, 0, sizeof chk);
	 		}
	 		now.clear();
	 		mn = inf;
	 		memset(chk, 0, sizeof chk);
 			mid /= 2;
 		}
 		printf("Network %d\n", ++idx);
 		printf("The bandwidth is %d.\n\n", sum);
	}
}