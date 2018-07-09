#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MOD = 2009;

int n, m, dp[105][105][25], mp[25][25];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			mp[i][j] = input();
		}
	}
	m = input();
	for(int i = 1; i <= m; ++i) {
		int now = input();
		dp[i][i][now]++;
	}
	for(int i = m-1; i >= 1; --i) {
		for(int j = i+1; j <= m; ++j) {
			for(int k = i; k < j; ++k) {
				for(int x = 0; x < n; ++x) {
					for(int y = 0; y < n; ++y) {
						dp[i][j][mp[x][y]] += dp[i][k][x]*dp[k+1][j][y];
						dp[i][j][mp[x][y]] %= MOD;
	}	}	}	}	}
	for(int i = 0; i < n; ++i) {
		printf("%d\n", dp[1][m][i]);
	}
}