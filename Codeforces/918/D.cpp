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

int n, m, dp[105][105][28];
vector<P> g[105];

bool mic(int ll, int rr, int s) {
	if(dp[ll][rr][s] != -1) return dp[ll][rr][s];
	for(auto v:g[ll]) if(v.y >= s) {
		if(!mic(rr, v.x, v.y)) return dp[ll][rr][s] = true;
	}
	return dp[ll][rr][s] = false;
}

int main() {
	red();
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);
		g[a].emplace_back(b, c-'a');
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) printf("%c", (mic(i, j, 0)?'A':'B'));
		puts("");
	}
}