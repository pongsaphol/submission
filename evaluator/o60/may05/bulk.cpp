#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1 << 17;

int n, m, A[N];
bool chk[N], in[N];
vector<pii> g[N];

struct data {
	int lazy = 0, status = 0;
	int sum = 0, mx = -1e9-1, cntmax = 0, cntmxa = 0;
	data() { }
	data(int idx) {
		if(in[idx]) mx = A[idx], cntmax = cntmxa = 1;
		sum = A[idx];
	}
	friend inline data operator+(const data &a, const data &b) {
		data ret;
		ret.sum = a.sum + b.sum;
		ret.cntmxa = a.cntmxa + b.cntmxa;
		if(a.mx == b.mx) ret.mx = a.mx, ret.cntmax = a.cntmax + b.cntmax;
		else if(a.mx > b.mx) ret.mx = a.mx, ret.cntmax = a.cntmax;
		else ret.mx = b.mx, ret.cntmax = b.cntmax;
		return ret;
	}
} t[N << 1];

int dfs(int u, int p) {
	chk[u] = true;
	for(auto v : g[u]) if(v.x != p) {
		if(chk[v.x]) {
			in[v.y] = true;
			return v.x;
		} else {
			int ret = dfs(v.x, u);
			if(ret) {
				in[v.y] = true;
				if(ret == u) return 0;
				return ret;
			}
		}
	}
	return 0;
}

void pushlazy(int p, int l, int r) {
	if(t[p].status == 1) {
		t[p].sum += (r-l+1) * t[p].lazy;
		if(t[p].cntmax) t[p].mx += t[p].lazy;
		if(l != r) {
			t[p << 1].lazy += t[p].lazy;
			t[p << 1 | 1].lazy += t[p].lazy;
			if(!t[p << 1].status) t[p << 1].status = 1;
			if(!t[p << 1 | 1].status) t[p << 1 | 1].status = 1;
		}
	} else if(t[p].status == 2) {
		t[p].sum = (r-l+1) * t[p].lazy;
		if(t[p].cntmax) {
			t[p].mx = t[p].lazy;
			t[p].cntmax = t[p].cntmxa;
		}
		if(l != r) {
			t[p << 1].lazy = t[p].lazy, t[p << 1].status = 2;
			t[p << 1 | 1].lazy = t[p].lazy, t[p << 1 | 1].status = 2;
		}
	}
	t[p].status = t[p].lazy = 0;
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = data(l);
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
	t[p] = t[p << 1] + t[p << 1 | 1];
}

void update(int met, int x, int y, int v, int p = 1, int l = 1, int r = n) {
	pushlazy(p, l, r);
	if(x <= l && r <= y) {
		t[p].lazy = v, t[p].status = met;
		pushlazy(p, l, r);
		return;
	}
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	update(met, x, y, v, p << 1, l, m), update(met, x, y, v, p << 1 | 1, m + 1, r);
	t[p] = t[p << 1] + t[p << 1 | 1];
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int u, v;
		scanf("%d %d %d", &u, &v, &A[i]);
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	dfs(1, 0);
	build();
	while(m--) {
		int met, a, b, c;
		scanf("%d %d %d %d", &met, &a, &b, &c);
		update(met, a, b, c);
		printf("%d %d\n", t[1].sum - t[1].mx, t[1].cntmax);
	}
}