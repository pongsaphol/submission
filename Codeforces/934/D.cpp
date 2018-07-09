#include <bits/stdc++.h>
using namespace std;

long long n;
int m;

int main() {
	// freopen("r", "r", stdin);
	scanf("%lld %d", &n, &m);
	m = -m;
	vector<int> ans;
	ans.reserve(1000000);
	while(n != 0) {
		if(ans.size() > 1000000) return !printf("-1\n");
		int c = (n % m);
		n /= m;
		if(c < 0) {
			c += abs(m);
			n++;
		}
		ans.emplace_back(c);
	}
	printf("%d\n", ans.size());
	for(auto x : ans) printf("%d ", x);
}