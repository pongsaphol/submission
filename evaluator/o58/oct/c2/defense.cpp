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

const int MAXN = 3001;

int n, m, A[MAXN], dp[MAXN][MAXN];

int f(int x) {
	if(x < 0) return 0;
	return x;
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	for(int i = 1; i <= n; ++i) A[i] = input(), dp[i][0] = 1e9;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < m; ++j){
			dp[i][j] = min(dp[i][j-1], dp[f(i-j)][m-j] + A[i]);
	}	}
	int mn = 1e9;
	for(int i = n; i > n - m + 1; --i) {
		mn = min(mn, dp[i][m-(n-i)-1]);
	}
	printf("%d\n", mn);
}
