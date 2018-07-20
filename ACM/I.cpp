#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define x first
#define y second
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	vector<iii> V;
	for(int i = 1, a, b; i <= n; ++i) {
		scanf("%d %d", &a, &b);
		V.emplace_back(a, b, i);	
	}
	sort(V.begin(), V.end(), [&](const iii &a, const iii &b) {
		if(get<1>(a) == get<1>(b)) return max(get<0>(a), get<1>(a)) < max(get<0>(b), get<1>(b));
		return get<1>(a) < get<1>(b);
	});
	vector<int> ans;
	for(auto x : V) {
		if(m >= max(get<1>(x), get<0>(x))) ans.emplace_back(get<2>(x)), m -= get<1>(x);	
	}
	printf("%d\n", (int)ans.size());
	for(auto x : ans) printf("%d ", x);
}
