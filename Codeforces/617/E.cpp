#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

struct data {
	int x, y, idx;
	data(int x, int y, int idx) : x(x), y(y), idx(idx) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.y < b.y;
	}
};

const int MAXN = 1e5 + 5;

int n, m, cnt[1 << 20], pref[MAXN], k;
long result;

void add(int v) {
	result += cnt[v^k];
	cnt[v]++;
}

void del(int v) {
	cnt[v]--;
	result -= cnt[v^k];
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	int sz = sqrt(n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", pref + i);
		pref[i] ^= pref[i-1];
	}
	vector<vector<data> > block(n/sz + 2, std::vector<data> ());
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y++;
		block[x/sz].emplace_back(x, y, i);
	}
	for(auto &i : block) sort(all(i));
	vector<long> ans(m);
	for(int i = 0; i < block.size(); ++i) {
		int l = i*sz, r = i*sz;
		for(auto &q : block[i]) {
			while(r < q.y) add(pref[r++]);
			while(l < q.x) del(pref[l++]);
			while(l > q.x) add(pref[--l]);
			ans[q.idx] = result;
		}
		for(int j = l; j < r; ++j) del(pref[j]);
	}
	for(auto i : ans) printf("%lld\n", i);
}