#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m;
vector<int> t[N<<1];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0, ret; i < n; ++i) scanf("%d", &ret), t[i+n].emplace_back(ret);
	for(int i = n-1; i; --i) {
		for(auto x : t[i<<1]) t[i].emplace_back(x);
		for(auto x : t[i<<1|1]) t[i].emplace_back(x);
		sort(t[i].begin(), t[i].end());
	} 
	while(m--) {
		int l, r, z; scanf("%d %d %d", &l, &r, &z); l--, r--;
		int sum = 0;
		auto f = [&](vector<int> &v) { sum += upper_bound(v.begin(), v.end(), z) - lower_bound(v.begin(), v.end(), z); };
		for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) f(t[l++]);
			if(r & 1) f(t[--r]);
		}
		printf("%d\n", sum);
	}
}