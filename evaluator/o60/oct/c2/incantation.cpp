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

const int MAXN = (1<<7) + 5;

int n, m;
long bt[MAXN], dp[MAXN][MAXN], inf = 1e9;
int A[MAXN];

int main() {
	red();
	scanf("%d %d", &n, &m);
	int lm = (1<<m), im = (1<<(m-1));
	fill(dp[0], dp[MAXN-1] + MAXN, -inf);
	for(int i = 0; i < lm; ++i) {
		int cost;
		scanf("%d", &cost);
		A[i] = dp[i>>1][i] = dp[im|i>>1][i] = cost; 
	}
	for(n -= m-1; n > 0; n >>= 1) {
		if(n & 1) { // 11
			long cbt[MAXN];
			mem(cbt);
			for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j) {
				if(cbt[j] < bt[i] + dp[i][j]) {
					cbt[j] = bt[i] + dp[i][j];
					// printf("->%d %d %lld\n", i, j, cbt[j]);
				}
				// cbt[j] = max(cbt[j], bt[i] + dp[i][j]);
			}
			for(int i = 0; i < lm; ++i)
			bt[i] = cbt[i];
		}
		long cdp[MAXN][MAXN];

		for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j)
		for(int k = 0; k < lm; ++k) cdp[i][j] = max(cdp[i][j], dp[i][k] + dp[k][j]);
		for(int i = 0; i < lm; ++i) {
			for(int j = 0; j < lm; ++j)
				dp[i][j] = cdp[i][j];
		}
	}
	printf("%lld\n", *max_element(bt, bt+MAXN));
}
/*
5 3
0 
0
0
10 011
0
0
2 110
0
*/
