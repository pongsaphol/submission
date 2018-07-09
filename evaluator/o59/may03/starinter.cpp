#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

struct item {
	long key;
	int prio, cnt;
	item *l, *r;
	item(int key) : key(key), prio(rand()), cnt(1), l(NULL), r(NULL) { }
};

using pitem = item*;
int cnt(pitem t) { return t ? t->cnt : 0; }
void upd(pitem t) { if(t) t->cnt = cnt(t->l) + cnt(t->r) + 1; }

void split(pitem t, long key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(key <= t->key) split(t->l, key, l, t->l), r = t;
	else split(t->r, key, t->r, r), l = t;
	upd(t);
}

void split2(pitem t, long key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(key < t->key) split2(t->l, key, l, t->l), r = t;
	else split2(t->r, key, t->r, r), l = t;
	upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(r->l, l, r->l), t = r;
	else merge(l->r, l->r, r), t = l;
	upd(t);
}

const int MAXN = 2e5 + 5;

vector<pii> g[MAXN];
int n, k;
long sum;
long dp[MAXN];

void dfs(int u, int p, int lev, pitem &t) {
	for(auto v : g[u]) if(v.x == p) dp[lev] = dp[lev-1] + v.y;
	if(lev) {
		pitem t1, t2;
		split(t, dp[lev] - k, t1, t2);
		sum += cnt(t2);
		merge(t, t1, t2);
		split(t, dp[lev], t1, t2);
		merge(t, t1, new item(dp[lev]));
		merge(t, t, t2);
	}
	for(auto v : g[u]) if(v.x != p and g[v.x].size() <= 2) dfs(v.x, u, lev + 1, t);
}

void print(pitem t, int lev = 0) {
	if(!t) return;
	print(t->l, lev+1);
	printf("%d = %lld\n", lev, t->key);
	print(t->r, lev+1);
}

queue<long> Q;

void dfs2(int u, int p, int lev, pitem &t) {
	for(auto v : g[u]) if(v.x == p) dp[lev] = dp[lev-1] + v.y;
	pitem t1, t2;
	split2(t, k - dp[lev], t1, t2);
	sum += cnt(t1);
	merge(t, t1, t2);
	Q.push(dp[lev]);
	for(auto v : g[u]) if(v.x != p) dfs2(v.x, u, lev+1, t);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	int num = 0;
	for(int i = 1; i <= n; ++i) {
		pitem ret = new item(0);
		if(g[i].size() == 1) dfs(i, -1, 0, ret);
		if(g[i].size() > 2) num = i;
	}
	if(!num) return !printf("%lld\n", sum >> 1);
	pitem t = new item(0);
	for(auto v : g[num]) {
		dfs2(v.x, num, 1, t);
		while(!Q.empty()) {
			long now = Q.front();
			Q.pop();
			pitem t1, t2;
			split2(t, now, t1, t2);
			merge(t, t1, new item(now));
			merge(t, t, t2);
		}
	}
	printf("%lld\n", sum);
}