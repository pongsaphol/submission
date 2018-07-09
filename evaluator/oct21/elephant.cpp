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

int dp[100005];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input(), x = input();
	x = input();
	for(int i = 3; i <= n; ++i) {
		x = input();
		dp[i] = max(dp[i-1], dp[i-3] + x);
	}
	printf("%d\n", dp[n]);
}