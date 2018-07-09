#include <iostream>
#include <algorithm>
#define long long long
using namespace std;

int n, m, A[25];
long inf = 1e18;

long rec(int lv, long x) {
	long now = (x<<1) - A[lv];
	now++;
	if(now < 2) return -inf;
	if(lv == 1) return now;
	if(now%2 == 0) {
		return 2*rec(lv-1, now/2);
	} else {
		return rec(lv-1, now/2) + rec(lv-1, now/2 + 1);
	}
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i < n; ++i) cin >> A[i];
	long ans = rec(n-1, m);
	if(ans < 0) cout << "-1" << endl;
	else cout << ans << endl;
}