#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1e5 + 5;

struct data{
	int l, r, dl, dm, dr;
};
data t[20*MAXN];

int n, ver[MAXN], ptr, cv, ret[MAXN];
vector<int> coor, inp, tod[MAXN];

int build(int p, int l = 1, int r = n) {
	if(l == r) return p;
	int m = (l + r) >> 1;
	t[p].l = build(++ptr, l, m), t[p].r = build(++ptr, m+1, r);
	return p;
}

int update(int x, int p, int l = 1, int r = n) {
	// printf("%d : %d %d :: %d %d\n", p, l, r, t[p].l, t[p].r);
	t[++ptr] = t[p];
	p = ptr;
	if(l == r) {
		t[p].dl = t[p].dr = t[p].dm = 1;
		return p;
	}
	int m = (l + r) >> 1;
	if(x <= m) t[p].l = update(x, t[p].l, l, m);
	else t[p].r = update(x, t[p].r, m+1, r);
	// printf("%d %d %d %d\n", l, r, t[t[p].l].dm, t[t[p].r].dm);
	t[p].dl = t[t[p].l].dl; t[p].dr = t[t[p].r].dr;
	if(t[p].dl == (m-l+1)) t[p].dl += t[t[p].r].dl;
	if(t[p].dr == (r - m)) t[p].dr += t[t[p].l].dr;
	t[p].dm = max({t[t[p].l].dm, t[t[p].r].dm, t[t[p].l].dr + t[t[p].r].dl});
	return p;
}

data query(int x, int y, int p, int l = 1, int r = n) {
	if(x <= l && r <= y) return t[p];
	if(x > r || l > y) return {0, 0, 0, 0, 0};
	int m = (l + r) >> 1;
	data d1 = query(x, y, t[p].l, l, m), d2 = query(x, y, t[p].r, m+1, r);
	data now;
	now.dl = d1.dl; now.dr = d2.dr;
	if(now.dl == (m-l+1)) now.dl += d2.dl;
	if(now.dr == (r - m)) now.dr += d1.dr;
	now.dm = max({d1.dm, d2.dm, d1.dr + d2.dl});
	return now;
}

void travel(int p, int l = 1, int r = n) {
	printf("%d %d %d :: %d\n", l, r, t[p].dm, p);
	if(l == r) return;
	int m = (l + r) >> 1;
	travel(t[p].l, l, m), travel(t[p].r, m+1, r);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		coor.emplace_back(now);
		inp.emplace_back(now);
	}
	sort(all(coor));
	coor.resize(unique(all(coor)) - coor.begin());
	for(int i = 0; i < inp.size(); ++i) {
		tod[lower_bound(all(coor), inp[i]) - coor.begin()].emplace_back(i+1);
	}
	ver[0] = build(++ptr);
	// travel(ver[0]);
	for(int i = coor.size() - 1; i >= 0; --i) {
		for(auto x : tod[i]) {
			// printf("%d\n", x);
			// travel(ver[cv]);
			int now = ver[cv];
			ver[++cv] = update(x, now);
			// travel(ver[cv]);
		}
		ret[i] = ver[cv];
	}
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int l = 0, r = coor.size() - 1;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(query(a, b, ret[m]).dm >= c) l = m;
			else r = m - 1;
		}
		printf("%d\n", coor[l]);
	}
}