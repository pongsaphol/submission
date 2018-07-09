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

int n, m, A[1005][1005], dp[3][1005][1005];

int f(int a, int b, int c) {
	return max(dp[a][b-1][c], dp[a][b][c-1]);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			A[i][j] = input();
		}
	}	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dp[0][i][j] = max(f(0,i,j), max(f(1,i,j), f(2,i,j)));
			dp[1][i][j] = f(0,i,j) + A[i][j];
			dp[2][i][j] = f(1,i,j) + A[i][j];
		}
	}
	printf("%d\n", max(dp[0][n][m], max(dp[1][n][m], dp[2][n][m])));
}