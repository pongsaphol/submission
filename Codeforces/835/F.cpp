#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

const int MAXN = 2e5 + 5;

int n;
bool chk[MAXN];
vector<P> g[MAXN], cy;

int dfs(int u, int p) {
	if(chk[u]) return u;
	chk[u] = true;
	for(auto v:g[u]) if(v.x != p) {
		int now = dfs(v.x, u);
		if(now == -1) {
			chk[u] = false;
			return -1;
		}
		if(now == u) {
			cy.emplace_back(u, v.y);
			return -1;
		} else if(now != 0) {
			cy.emplace_back(u, v.y);
			return now;
		}
	}
	chk[u] = false;
	return 0;
}

long dp[MAXN], ans;

long mic(int u, int p) {
	long mx1 = 0, mx2 = 0;
	for(auto v:g[u]) if(v.x != p && !chk[v.x]) {
		auto now = mic(v.x, u) + v.y;
		if(now > mx1) swap(now, mx1);
		if(now > mx2) swap(now, mx2);
	}
	ans = max(ans, mx1 + mx2);
	return dp[u] = mx1;
}

long dpl[MAXN], dpr[MAXN], dpll[MAXN], dprr[MAXN];

long solve() {
	dfs(1, 1);
	int sz = cy.size();
	for(auto v:cy) mic(v.x, v.x);
	dbg(dp[3]);
	cy.emplace_back(0, 0);
	reverse(all(cy));
	for(auto v:cy) dbg2(v.x, v.y);
	long best = 0, dist = 0;
	for(int i = 1; i <= sz; ++i) {
		dpl[i] = max(dpl[i-1], best + dp[cy[i].x]);
		dpll[i] = max(dpll[i-1], dist + dp[cy[i].x]);
		best = max(best, dp[cy[i].x]) + cy[i].y;
		dist += cy[i].y;
	}
	best = 0, dist = 0;
	for(int i = sz; i > 0; --i) {
		dpr[i] = max(dpr[i+1], best + dp[cy[i].x]);
		dprr[i] = max(dprr[i+1], dist + dp[cy[i].x]);
		best = max(best, dp[cy[i].x]) + cy[i-1].y;
		dist += cy[i-1].y;
	}
	long ret = max(dpl[sz], dpr[1]);
	for(int i = 1; i < sz; ++i) {
		ret = min(ret, max(max(dpl[i], dpr[i+1]), dpll[i] + dprr[i+1] + cy[sz].y));
	}
	return max(ret, ans);
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	printf("%lld\n", solve());
}