#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int d[305][305], P[1005];
vector<int> g[305];

int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

typedef struct data {
	int u, v, w;
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
} data;

int main() {
	// freopen("r", "r", stdin);
	int n, t;
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; ++i) {
		P[i] = i;
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &d[i][j]);
		}
	}
	priority_queue<data> Q;
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			Q.push({i, j, d[i][j]});
		}
	}
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		int u = find(now.u), v = find(now.v);
		if(u != v) {
			g[now.u].emplace_back(now.v);
			g[now.v].emplace_back(now.u);
			P[u] = v;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(g[i].size() >= 3) {
			printf("%d\n", i);
			if(t == 2) printf("%d\n", g[i].size());
			return 0;
		}
	}
}