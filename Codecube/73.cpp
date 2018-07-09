#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 200;

int arr[MAXN+5][MAXN+5];
int dp[MAXN+5][MAXN+5];

int main() {
	// freopen("r", "r", stdin);
	int r, c;
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i = r; i >= 1; --i) {
		for(int j = 1; j <= c; ++j) {
			dp[i][j] = max(dp[i+1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	int mx = dp[1][c];
	dp[r][1] = arr[r][1];
	for(int i = 2; i <= c; ++i) {
		dp[r][i] = dp[r][i-1] + arr[r][i];
	}
	for(int j = r-1; j >= 1; --j) {
		dp[j][1] = dp[j+1][1] + arr[j][1];
	}
	for(int i = r-1; i >= 1; --i) {
		for(int j = 2; j <= c; ++j) {
			dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	int mn = dp[1][c];
	printf("%d\n", mx-mn);
}