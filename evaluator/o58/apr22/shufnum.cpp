#include <bits/stdc++.h>
using namespace std;

struct item {
	int val, prio, lz;
	item *l, *r;
	item(int val) : val(val), prio(rand()), lz(0), l(NULL), r(NULL) {}
};

using pitem = item*;

void push(pitem t) {
	if(t) if(t->lz) {
		t->val += t->lz;
		if(t->l) t->l->lz += t->lz;
		if(t->r) t->r->lz += t->lz;
		t->lz = 0;
	}
}

void split(pitem t, int val, pitem &l, pitem &r) {
	push(t);
	if(!t) return void(l = r = NULL);
	if(t->val < val) split(t->r, val, t->r, r) , l = t;
	else split(t->l, val, l, t->l), r = t;
}

void merge(pitem &t, pitem l, pitem r) {
	push(l), push(r);
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(r->l, l, r->l), t = r;
	else merge(l->r, l->r, r), t = l;
}

bool find(pitem t, int val) {
	push(t);
	if(!t) return false;
	if(t->val == val) return true;
	if(t->val > val) return find(t->l, val);
	return find(t->r, val);
}

void print(pitem t) {
	if(!t) return;
	push(t);
	print(t->l);
	printf("%d ", t->val);
	print(t->r);
}

int n, m;
pitem t;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int ret; scanf("%d", &ret);
		merge(t, t, new item(ret));
	}
	while(m--) {
		int met, a, b, c; scanf("%d %d", &met, &a);
		bool st = find(t, a);
		if(met == 1) printf("%d\n", st);
		else {
			scanf("%d %d", &b, &c);
			if(!st) continue;
			pitem t1, t2;
			split(t, a, t1, t2);
			if(t1) t1->lz += b;
			if(t2) t2->lz += c;
			merge(t, t2, t1);
		}	
	}
}