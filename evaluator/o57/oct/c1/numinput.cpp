/*
TASK: o57_oct_c1_numinput
*/
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
 
int n, m, A[1005], dp[1005][1005];

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	int len = 0;
	for(int i = 1; i <= n; ++i) {
		int now = input();
		for(int j = len + 1; j <= len+now; ++j) {
			A[j] = i;
		}
		len += now;
	}
	int prev = 0;
	while(m--) {
		int now = input();
		for(int i = prev+1; i < now; ++i) A[i] = 0;
		prev = now;
	}
	for(int i = prev+1; i <= len; ++i) A[i] = 0;
	dp[1][1] = 1;
	for(int i = 2; i <= len; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(A[i] != 0 && A[i] != j) continue;
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= 9901;
		}
	}
	printf("%d\n", dp[len][n]);
}