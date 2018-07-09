#include <bits/stdc++.h>
using namespace std;

struct item {
	int val, cnt, prio;
	bool lazy = false;
	item *l, *r;
	item() { }
	item(int val) : val(val), cnt(1), prio(rand()), lazy(false), l(NULL), r(NULL) { }
};

using pitem = item*;

int cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt(pitem t) { if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r); }

void push(pitem t) {
	if(t and t->lazy) {
		t->lazy = false;
		swap(t->l, t->r);
		if(t->l) t->l->lazy ^= 1;
		if(t->r) t->r->lazy ^= 1;	
	}
}

void split(pitem t, int val, pitem &l, pitem &r) {
	push(t);
	if(!t) return void(l = r = NULL);
	if(val <= cnt(t->l)) split(t->l, val, l, t->l), r = t;
	else split(t->r, val - cnt(t->l) - 1, t->r, r), l = t;
	upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
	push(l), push(r);
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(r->l, l, r->l), t = r;
	else merge(l->r, l->r, r), t = l;
	upd_cnt(t);
}

int find(pitem t) {
	push(t);
	if(!t->l) return t->val;
	return find(t->l);
}

void print(pitem t) {
	push(t);
	if(!t) return;
	print(t->l);
	printf("%d ", t->val);
	print(t->r);
}

int n;
pitem t;

int main() {
	srand(time(NULL));
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		merge(t, t, new item(now));
	}

	int cnt = 0;
	while(1) {
		int ret = find(t);
		if(ret == 1) return !printf("%d\n", cnt);
		cnt++;
		pitem t1, t2;
		split(t, ret, t1, t2);
		if(t1) t1->lazy ^= 1;
		merge(t, t1, t2);
	} 
}