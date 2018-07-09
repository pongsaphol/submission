#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+1;

struct item {
	int val, cnt, prio;
	long sval;
	item *l, *r;
	item(int val) : val(val), cnt(1), prio(rand()), sval(1), l(NULL), r(NULL) { }
};

using pitem = item*;

int cnt(pitem t) { return t ? t->cnt : 0; }
long val(pitem t) { return t ? t->sval : 0; }
void upd_cnt(pitem t) { 
	if(t) t->cnt = cnt(t->l) + cnt(t->r) + 1, t->sval = val(t->l) + val(t->r) + t->val;
}

void split(pitem t, int key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(val(t) - val(t->r) <= key) split(t->r, key - val(t) + val(t->r), t->r, r), l = t;
	else split(t->l, key, l, t->l), r = t;
	upd_cnt(t);
}

void split2(pitem t, int key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(t->val <= key) split2(t->r, key, t->r, r), l = t;
	else split2(t->l, key, l, t->l), r = t;
	upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void get(pitem t, vector<int> &v) {
	if(!t) return;
	v.emplace_back(t->val);
	get(t->l, v), get(t->r, v);
}

void print(pitem t) {
	if(!t) return;
	print(t->l);
	printf("%d %lld\n", t->val, t->sval);
	print(t->r);
}

int n, m, root, A[N];
long ans, L[N];
vector<vector<int> > g;

pitem dfs(int u, int p) {
	pitem t = new item(A[u]);
	for(auto v : g[u]) if(v != p) {
		pitem now = dfs(v, u);
		if(cnt(now) > cnt(t)) swap(now, t);
		vector<int> vv; get(now, vv);
		for(auto x : vv) {
			pitem t1, t2; split2(t, x, t1, t2);
			merge(t, t1, new item(x));
			merge(t, t, t2);
		}
	}
	pitem t1, t2;
	split(t, m, t1, t2);
	ans = max(ans, L[u] * cnt(t1));
	merge(t, t1, t2);
	return t;
}

int main() {
	srand(time(NULL));
	scanf("%d %d", &n, &m);
	g.resize(n+1);
	for(int i = 1, p; i <= n; ++i) {
		scanf("%d %d %lld", &p, A+i, L+i);
		if(p) g[p].emplace_back(i);
		else root = i;
	}
	dfs(root, 0);
	printf("%lld\n", ans);
}