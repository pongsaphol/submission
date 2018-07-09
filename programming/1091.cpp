#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 3e5 + 5;

int n,dp[MAXN];
vector<int> g[MAXN];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) dp[i] = 1;
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int mx = 0;
		for(auto j:g[i]) if(j < i) mx = max(mx, dp[j]);
		dp[i] += mx;
		ans = max(ans, dp[i]);
		// printf("%d %d\n", i, dp[i]);
	}
	printf("%d\n", ans);
}