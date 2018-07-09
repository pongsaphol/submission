#include <bits/stdc++.h>
#define long long long
using namespace std;

struct data {
	int x, y, idx;
	data(int x, int y, int idx) : x(x), y(y), idx(idx) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.y < b.y;
	}
};

void solve() {
	int n, m;
	scanf("%d", &n);
	vector<int> pref(n+1);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		pref[i] = pref[i-1] + now;
	}
	long sum = 0;
	int sz = sqrt(n);
	vector<vector<data> > block(n / sz + 2, vector<data> ());
	scanf("%d", &m);
	vector<int> ans(m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b++;
		block[a/sz].emplace_back(a, b, i);
	}
	for(int i = 0; i < block.size(); ++i) {
		int l = i*sz, r = i*sz;
		for(auto &q : block[i]) {
			while(r < q.y) add(r++);
			while(l < q.x) del(l++);
			while(l > q.x) add(--l);
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--) solve();
}