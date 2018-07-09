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

const int MAXN = 1e3+5;

int qs[MAXN][MAXN];
int dp[2][MAXN];
int main() {
	red();
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		char now;
		scanf(" %c", &now);
		now = (now=='#'?1:0);
		qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + now;
	}
	for(int i = 1; i <= m; ++i) {
		dp[0][i] = dp[1][i] = 1e9;
		for(int j = a; j <= b; ++j) {
			if(i-j < 0) break;
			dp[0][i] = min(dp[0][i], dp[1][i-j] + qs[n][i] - qs[n][i-j]);
			dp[1][i] = min(dp[1][i], dp[0][i-j] + n*j - qs[n][i] + qs[n][i-j]);
		}
	}
	cout << min(dp[0][m], dp[1][m]);
}