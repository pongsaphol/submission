#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool chk[1005];
vector<int> g[1005];

bool dfs(int idx) {
	if(chk[idx]) return false;
	chk[idx] = true;
	bool st = true;
	for(auto x:g[idx]) st &= dfs(x);
	return st;
}

int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int m;
		scanf("%d", &m);
		while(m--) {
			int x;
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; ++i) {
		memset(chk, false, sizeof chk);
		if(dfs(i)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}