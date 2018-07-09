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

const int MAXN = 1e2+5;

int n, ans = -1, x[MAXN], y[MAXN];
bool chk[MAXN];

void dfs(int u) {
	chk[u] = true;
	for(int i = 1; i <= n; ++i) if(x[i] == x[u] || y[i] == y[u]) if(!chk[i]) dfs(i);
}

int main() {
	red();
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; ++i) if(!chk[i]) dfs(i), ans++;
	cout << ans << endl;
}