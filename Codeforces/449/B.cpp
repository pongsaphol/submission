#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, k;
bool chk[MAXN];

struct data {
	long x, y, z;
	data(long xx, long yy, long zz) { x = xx, y = yy, z = zz; }
	friend inline bool operator<(const data &a, const data &b) {
		if(a.x == b.x) return a.z;
		return a.x > b.x;
	}
};

vector<data> g[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	while(m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w, 0);
		g[v].emplace_back(u, w, 0);
	}
	priority_queue<data> Q;
	for(int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[1].emplace_back(a, b, 1);
		g[a].emplace_back(1, b, 1);
	}
	Q.emplace(0, 1, false);
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(chk[now.y]) continue;
		chk[now.y] = true;
		if(now.z) k--;
		for(auto v : g[now.y]) Q.emplace(now.x + v.y, v.x, v.z);
	}
	printf("%d\n", k);
}