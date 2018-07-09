#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

const int MAXN = 1e4+5;

int n, ptr, col[MAXN], dp[MAXN], idx[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p, int now) {
	if(now != col[u]) {
		// printf("%d %d\n", u, now);
		ptr++;
		now = col[u];
	}
	for(auto v:g[u]) if(v != p) {
		dfs(v, u, now);
	}
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		g[now].emplace_back(i);
		g[i].emplace_back(now);
	}
	for(int i = 1; i <= n; ++i) scanf("%d", col+i);
	dfs(1, 1, -1);
	printf("%d\n", ptr);
}