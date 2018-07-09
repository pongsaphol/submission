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

const int MAXN = 1e5+5;

int n, m, mn = 21;
vector<int> g[MAXN], ans;
bool chk[MAXN];

void dfs(int u, int cnt) {
	if(cnt > mn) return;
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
		if(g[u].size() > 1) {
			chk[u] = true;
			dfs(u+1, cnt+1);
			chk[u] = false;
		} 
	} else dfs(u+1, cnt);
}

int main() {
	red();
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