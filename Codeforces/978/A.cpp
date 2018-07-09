#include <bits/stdc++.h>
using namespace std;

bool is[1005];

int main() {
	int n; scanf("%d", &n);
	vector<int> V;
	while(n--) {
		int x; scanf("%d", &x);
		V.emplace_back(x);
	}
	reverse(V.begin(), V.end());
	vector<int> ans;
	for(auto x : V) {
		if(is[x]) continue;
		is[x] = true;
		ans.emplace_back(x);
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(auto x : ans) printf("%d ", x);
}