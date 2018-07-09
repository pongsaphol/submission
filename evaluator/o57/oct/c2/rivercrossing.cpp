#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5+5, MOD = 30011;

int n, m, k, l, dp[MAXN][15];
P g[MAXN];
vector<int> D[MAXN];
int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> k >> l;
	while(l--) {
		int a = input(), b = input();
		D[a].emplace_back(b+n);
		D[b+n].emplace_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		sort(all(D[i]));
		int a = input(), b = input();
		g[i] = {b+n, n+a+b-1};
	}
	for(int i = n+1; i <= 2*n; ++i) {
		sort(all(D[i]));
		int a = input(), b = input();
		g[i] = {b, b+a-1};
	}
	int sum = 0;
	for(int i = n+1; i <= 2*n; ++i) {
		dp[i][0] = (dp[i-1][0] + 1)%MOD;
	}
	for(int i = 1; i <= k; ++i) {
		if(i&1)for(int j = 1; j <= n; ++j) {
			int L = g[j].x-1, R = g[j].y;
			for(auto x:D[j]) {
				if(x > L && x <= R) {
					dp[j][i] -= dp[x][i-1] - dp[x-1][i-1];
					R++;
				}
			}
			R = min(R, 2*n);
			dp[j][i] += dp[R][i-1] - dp[L][i-1] + dp[j-1][i];
			dp[j][i] = (dp[j][i] + MOD)% MOD;
		}
		else for(int j = n+1; j <= 2*n; ++j) {
			int L = g[j].x-1, R = g[j].y;
			for(auto x:D[j]) {
				if(x > L && x <= R) {
					dp[j][i] -= dp[x][i-1] - dp[x-1][i-1];
					R++;
				}
			}
			R = min(R, n);
			dp[j][i] += dp[R][i-1] - dp[L][i-1] + dp[j-1][i] + 1;
			dp[j][i] = (dp[j][i] + MOD)% MOD;
		}
	}
	if(k%2)printf("%d\n", dp[n][k]);
	else printf("%d\n", dp[n][k-1]);
}