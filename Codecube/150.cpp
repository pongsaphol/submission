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

const int MAXN = 1e5+5, inf = 1e9;

int cnt, cnts, dp[MAXN];
int main() {
	red();
	int n = input();
	int m = input();
	fill(dp, dp+MAXN, inf);
	dp[1] = 0;
	for(int i = 1; i <= n; ++i) {
		int now = input();
		if(dp[now] == inf) {
			for(int i = 1; i*now <= 100000; ++i) {
				dp[i*now] = min(dp[i*now], dp[i]+1);
			}
		} else {
			cnt++;
			cnts += dp[now];
		}
	}
	printf("%d ", cnt);
	if(m == 2) printf("%d\n", cnts);
}