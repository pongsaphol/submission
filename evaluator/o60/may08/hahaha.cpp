#include <bits/stdc++.h>
#define long long long
using namespace std;

struct item {
	long inv;
	int num[5], val, prio, cnt, lazy1;
	item *l, *r;
	bool lazy2;
	item(int val) : val(val), prio(rand()), cnt(1), lazy1(-1), lazy2(false), inv(0), l(NULL), r(NULL) { num[val]++; }
};

using pitem = item*;

long c2(long x) { return (x * (x-1)) >> 1; }

int cnt(pitem t) { return t ? t->cnt : 0; }

void push(pitem t) {
	if(!t) return;
	if(t->lazy1 != -1) {
		memset(t->num, 0, sizeof t->num);
		t->val = t->lazy1;
		t->num[t->lazy1] = t->cnt;
		t->inv = 0;
		if(t->l) t->l->lazy1 = t->lazy1;
		if(t->r) t->r->lazy1 = t->lazy1;
		t->lazy1 = -1;
	}
	if(t->lazy2) {
		t->lazy2 = false;
		t->inv =  c2(t->cnt) - t->inv;
		for(int i = 0; i < 5; ++i) t->inv -= c2(t->num[i]);
		swap(t->l, t->r);
		if(t->l) t->l->lazy2 ^= 1;
		if(t->r) t->r->lazy2 ^= 1;
	}
}

void upd_cnt(pitem t) {
	if(!t) return;
	push(t->l), push(t->r);
	t->cnt = cnt(t->l) + cnt(t->r) + 1;
	t->inv = (t->l ? t->l->inv : 0) + (t->r ? t->r->inv : 0);
	if(t->l and t->r) for(int i = 0; i < 5; ++i) for(int j = 0; j < i; ++j) t->inv += 1ll * t->l->num[i] * t->r->num[j];
	if(t->l) for(int i = 4; i != t->val; --i) t->inv += t->l->num[i];	
	if(t->r) for(int i = 0; i != t->val; ++i) t->inv += t->r->num[i];
	memset(t->num, 0, sizeof t->num);
	for(int i = 0; i < 5; ++i) t->num[i] = (t->l ? t->l->num[i] : 0) + (t->r ? t->r->num[i] : 0);
	t->num[t->val]++;
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
	else if(l->prio > r->prio) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void print(pitem t) {
	push(t);
	if(!t) return;
	print(t->l);
	printf("%d ", t->val);
	print(t->r);
}

pitem t;
int n, q;

int main() {
	srand(time(NULL));
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++i) {
		int ret; scanf("%1d", &ret);
		merge(t, t, new item(ret));
	}
	while(q--) {
		int T, a, b, c; scanf("%d %d %d", &T, &a, &b);
		pitem t1, t2;
		split(t, a-1, t, t1);
		split(t1, b-a+1, t1, t2);
		if(T == 1) {
			scanf("%d", &c);
			t1->lazy1 = c;
		}else if(T == 2) t1->lazy2 ^= 1;
		else printf("%lld\n", t1->inv);
		merge(t, t, t1);
		merge(t, t, t2);
	}
}