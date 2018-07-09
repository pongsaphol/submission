#include <bits/stdc++.h>
using namespace std;

struct data {
	int x, y, idx;
	data(int x, int y, int idx) : x(x), y(y), idx(idx) { }
	friend inline bool operator<(const data &a, const data &b) {
		if(a.x == b.x) return a.y > b.y;
		return a.x < b.x;
	}
};

int n;

int main() {
	vector<data> V;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		V.emplace_back(a, b, i);
	}
	sort(V.begin(), V.end());
	map<int, int> M;
	for(auto x : V) {
		auto it = M.lower_bound(x.y);
		if(it != M.end()) return !printf("%d %d\n", x.idx, it->second);
		M[x.y] = x.idx;
	}
	puts("-1 -1");
}