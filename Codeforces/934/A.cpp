#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
	// freopen("r", "r", stdin);
	vector<int> A, B;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int now;
		scanf("%d", &now);
		A.emplace_back(now);
	}
	for(int i = 0; i < m; ++i) {
		int now;
		scanf("%d", &now);
		B.emplace_back(now);
	}
	vector<long> ans;
	for(int i = 0; i < n; ++i) {
		long mx = -1e18;
		for(int j = 0; j < m; ++j) mx = max(mx, ((long)A[i]*B[j]));
		ans.emplace_back(mx);
	}
	sort(all(ans));
	cout << ans[ans.size()-2];
}