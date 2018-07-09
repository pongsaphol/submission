#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

struct data {
	int a, b, c;
	data(int a, int b, int c) : a(a), b(b), c(c) { }
	friend inline bool operator<(const data &a, const data &b) {
		return make_pair(make_pair(a.a, a.b), a.c) > make_pair(make_pair(b.a, b.b), b.c);
	}
};

const int MAXN = 1e5 + 5;

int n, sz, cnt, t[MAXN<<1];
vector<data> V;
vector<int> coor;

void upd(int x, int v) { for(t[x += sz] = v; x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]); }
int idx(int x) { return lower_bound(all(coor), x) - coor.begin(); }
int query(int l) {int r = 2*sz, mx = -1; for(l += sz; l < r; l >>= 1, r >>= 1) {
	if(l&1) mx = max(mx, t[l++]); if(r&1) mx = max(mx, t[--r]);} return mx; }
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	memset(t, -1, sizeof t);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V.emplace_back(a, b, c);
		coor.emplace_back(b);
	}
	sort(all(V)); sort(all(coor));
	coor.resize(unique(all(coor)) - coor.begin());
	sz = coor.size();
	for(auto x : V) {
		if(query(idx(x.b)) >= x.c) cnt++;
		else upd(idx(x.b), x.c);
	}
	printf("%d\n", cnt);
}