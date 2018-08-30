#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

int n, m, mn = 21;
vector<int> g[N], ans;
bool chk[N];

void dfs(int u, int cnt) {
	if(cnt >= mn) return;
	if(u > n) {
		if(cnt < mn) {
			mn = cnt;
			ans.clear();
			for(int i = 1; i <= n; ++i) if(chk[i]) ans.emplace_back(i);
		}
		return;
	}
	if(!chk[u]) {
		if(g[u].size() <= 20) {
			vector<int> ret;
			for(auto v:g[u]) {
				if(!chk[v]) {
					chk[v] = true;
					ret.emplace_back(v);
				}
			}
			dfs(u+1, cnt + ret.size());
			for(auto v:ret) chk[v] = false;
		}
		if(g[u].size() > 2) {
			chk[u] = true;
			dfs(u+1, cnt+1);
			chk[u] = false;
		} 
	} else dfs(u+1, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	printf("%d\n", ans.size());
	for(auto x : ans) printf("%d\n", x);
}
