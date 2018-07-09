#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 6005;

int n, k, A[MAXN], d[MAXN], lv[MAXN], mn = 1e9;
vector<int> g[MAXN];
bool chk[MAXN];

void bfs(int u) {
	memset(chk, 0, sizeof chk);
	queue<int> Q;
	chk[u] = true;
	Q.push(u);
	lv[u] = 0, d[u] = A[u];
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		if(d[u] >= k) mn = min(mn, lv[u]);
		for(auto v : g[u]) if(!chk[v]) {
			chk[v] = true;
			lv[v] = lv[u] + 1;
			d[v] = d[u] + A[v];
			Q.push(v);
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for(int i = 0; i < n; ++i) bfs(i);
	if(mn == 1000000000) return !printf("-1\n");
	if(mn == 0) mn = 1;
	printf("%d\n", mn);
}