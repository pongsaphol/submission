#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int arr[1005], dp[1005], pv[1005];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	int mx = 0, mxidx = 0;
	for(int i = 1; i <= n; ++i) {
		arr[i] = input();
		dp[i] = 1;
		for(int j = 1; j < i; ++j) {
			if(arr[j] < arr[i]) {
				if(dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pv[i] = j;
				}
			}
		}
		if(mx < dp[i]) {
			mx = dp[i];
			mxidx = i;
		}
	}
	stack<int> S;
	while(mxidx != 0) {
		S.push(arr[mxidx]);
		mxidx = pv[mxidx];
	}
	printf("%d\n", S.size());
	while(!S.empty()) {
		printf("%d ", S.top());
		S.pop();
	}
}