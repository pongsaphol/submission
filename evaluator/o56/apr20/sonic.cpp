#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

struct item {
	int val, sum, prio, cnt;
	item *l, *r;
	item(int val, int sum) : val(val), sum(sum), cnt(sum), prio(rand()), l(NULL), r(NULL) { }
};

using pitem = item*;
int cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt(pitem t) { if(t) t->cnt = t->sum + cnt(t->l) + cnt(t->r); }

void split(pitem t, int key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(t->val <= key) split(t->r, key, t->r, r), l = t;
	else split(t->l, key, l, t->l), r = t;
	upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

const int MAXN = 2e5 + 5;

struct data {
	int met, a, b, c;
	data() { }
	data(int met, int a, int b, int c) : met(met), a(a), b(b), c(c) { }
};

int n, l;
pitem t[MAXN];
vector<data> query;
vector<int> coord;

int idx(int val) { return (lower_bound(all(coord), val) - coord.begin()); }

void update(int x, int v, int p) {
	for(int i = x; i != 0; i -= i&-i) {
		pitem t1, t2;
		split(t[i], v, t1, t2);
		merge(t[i], t1, new item(v, p));
		merge(t[i], t[i], t2);
	}
}

int quer(int x, int v) {
	int sum = 0;
	for(int i = x; i <= n; i += i&-i) {
		pitem t1, t2;
		split(t[i], v, t1, t2);
		sum += cnt(t1);
		merge(t[i], t1, t2);
	}
	return sum;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	coord.emplace_back(INT_MIN);
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; ++i) {
		int met, a, b, c = 0;
		scanf("%d %d %d", &met, &a, &b);
		if(met == 1) scanf("%d", &c);
		coord.emplace_back(b - a);
		query.emplace_back(met, a, b, c);
	}
	sort(all(coord));
	coord.resize(unique(all(coord)) - coord.begin());
	for(auto x : query) {
		if(x.met == 1) update(idx(x.b - x.a), x.a + x.b, x.c);
		else printf("%d\n", quer(idx(x.b - x.a), x.b + x.a));
	}
}