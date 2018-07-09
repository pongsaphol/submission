#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int M = 1e9+7, MAXN = 1<<17;

struct node {
	node *l, *r;
	P sum, hash;
	int isum, cnt;
	bool lz;
	node(node *l, node *r, P sum, P hash, int isum, int cnt, bool lz) : l(l), r(r), sum(sum), hash(hash), isum(isum), cnt(cnt), lz(lz) { }
};

int n, m, pv[MAXN]
b;ool check[MAXN];
P H[MAXN];
node *d[MAXN];
vector<P> g[MAXN];
P add(P a, P b) { return P((a.x+b.x)%M, (a.y+b.y)%M); }
P sub(P a, P b) { return add(P(M, M), add(a, P(-b.x, -b.y))); }
P mul(P a, P b) { return P(((long)a.x*b.x)%M, ((long)a.y*b.y)%M); }

node *newleaf(P v) {
	return new node(NULL, NULL, v, P(0, 0), 1, 0, false);
}
node *newpar(node *l, node *r) {
	return new node(l, r, add(l->sum, r->sum), add(l->hash, r->hash), l->isum + r->isum, l->cnt + r->cnt, false);
}
node *newlazy(node *p) {
	return new node(p->l, p->r, p->sum, sub(p->sum, p->hash), p->isum, p->isum - p->cnt, !p->lz);
}

void push(node *p) {
	if(!p->lz) return;
	p->lz = false;
	if(p->l) {
		p->l = newlazy(p->l);
		p->r = newlazy(p->r);
	}
}

node *build(bool st, int l = 0, int r = MAXN) {
	if(l == r) if(st) return newleaf(H[l]);
	else {
		node *ret = newleaf(H[l]);
		ret->cnt = 1, ret->hash = H[l];
		return ret;
	}
	int m = (l + r) >> 1;
	return newpar(build(st, l, m), build(st, m+1, r));	
}

node *update(int x, int y, node *p, int l = 0, int r = MAXN) {
	push(p);
	if(x <= l && r <= y) return newlazy(p);
	if(x > r || l > y) return p;
	int m = (l + r) >> 1;
	return newpar(update(x, y, p->l, l, m), update(x, y, p->r, m+1, r));
}

int query(int x, int y, node *p, int l = 0, int r = MAXN) {
	push(p);
	if(x <= l && r <= y) return p->cnt;
	if(x > r || l > y) return 0;
	int m = (l + r) >> 1;
	return query(x, y, p->l, l, m) + query(x, y, p->r, m+1, r);
}

bool chk(node *a, node *b, int l = 0, int r = MAXN) {
	push(a), push(b);
	int m = (l + r) >> 1;
	if(!a->l) return (a->hash == P(0, 0));
	if(a->r->hash == b->r->hash) return chk(a->l, b->l, l, m);
	return chk(a->r, b->r, m+1, r);
}

node *pnode(node *p, int k) {
	if(!query(k, k, p)) return update(k, k, p);
	int l = k, r = MAXN;
	while(l < r) {
		int m = (l + r + 1) >> 1;
		if(query(k, m, p) != m-k+1) r = m-1;
		else l = m;
	}
	return update(k, l+1, p);
}

void print(node *p) {
	for(int i = 0; i < 5; ++i) {
		printf("%d", query(i, i, p));
	}
	printf("\n");
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	H[0] = P(1, 1);
	for(int i = 1; i < MAXN; ++i) H[i] = mul(H[i-1], P(2, 37));
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int s, t; scanf("%d %d", &s, &t);
	node *inf = build(false);
	fill(d, d+MAXN, inf);
	d[s] = build(true);
	auto cmp = [&](const int &a, const int &b) {return chk(d[b], d[a]);};
	priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);
	Q.emplace(s);
	int cnt = 0;
	while(!Q.empty()) {
		int u = Q.top();
		Q.pop();
		if(check[u]) continue;
		check[u] = true;
		for(auto v : g[u]) {
			if(check[v.x]) continue;
			node *ret = pnode(d[u], v.y);
			if(chk(ret, d[v.x])) {
				d[v.x] = ret;
				pv[v.x] = u;
				Q.emplace(v.x);
			}
		}
	}
	if(d[t] == inf) return !printf("-1\n");
	printf("%d\n", d[t]->hash.x);
	stack<int> S;
	while(t) {
		S.emplace(t);
		t = pv[t];
	}
	printf("%d\n", S.size());
	while(!S.empty()) {
		printf("%d ", S.top()); S.pop();
	}
}