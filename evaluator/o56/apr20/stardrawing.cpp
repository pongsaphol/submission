#include <bits/stdc++.h>
#define ps pair<int, multiset<int> > 
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

bool chk[MAXN];
int n, m;
vector<int> g[MAXN];
set<ps> S;

void dfs(int u, int p, ps &s, int cnt) {
	chk[u] = true;
	s.x++;
	if(g[u].size() == 3) {
		s.y.emplace(cnt);
		cnt = -1;
	}
	cnt++;
	if(g[u].size() == 1 && p) s.y.emplace(cnt);
	for(auto v : g[u]) if(v != p) {
		if(chk[v]) {
			s.y.emplace(-1);
			return;
		}
		dfs(v, u, s, cnt);
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for(int i = 1; i <= n; ++i) if(!chk[i] && g[i].size() <= 1) {
		ps now;
		now.x = 0;
		dfs(i, 0, now, 0);
		S.emplace(now);
	}
	for(int i = 1; i <= n; ++i) if(!chk[i]) {
		ps now;
		now.x = 0;
		dfs(i, 0, now, 0);
		S.emplace(now);
	}
	printf("%d\n", S.size());
}