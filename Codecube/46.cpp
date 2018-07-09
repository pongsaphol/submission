#include <bits/stdc++.h>
using namespace std;

struct data {
	int a, b, c;
	data(int a, int b, int c) : a(a), b(b), c(c) { }
};

const int N = 1<<18;

vector<int> coor;
vector<data> V;
int n, m, lz[N<<1], t[N<<1];
char cans[3][10] = {"eat", "work", "sleep"};
int idx[6] = {2, 0, 1, 0, 1, 0};
int get(int x) { return lower_bound(coor.begin(), coor.end(), x) - coor.begin(); }

void pushlazy(int p, int l, int r) {
	if(lz[p]) {
		t[p] += lz[p];
		if(l != r) lz[p<<1] += lz[p], lz[p<<1|1] += lz[p];
		lz[p] = 0;
	}
}

void update(int x, int y, int p = 1, int l = 1, int r = coor.size()) {
	pushlazy(p, l, r);
	if(x <= l and r <= y) { lz[p]++, pushlazy(p, l, r); return; }
	if(x > r or l > y) return;
	int m = (l + r) >> 1;
	update(x, y, p<<1, l, m), update(x, y, p<<1|1, m+1, r);
}

int query(int x, int p = 1, int l = 1, int r = coor.size()) {
	pushlazy(p, l, r);
	if(l == r) return t[p] %= 6;
	int m = (l + r) >> 1;
	if(x <= m) return query(x, p<<1, l, m);
	return query(x, p<<1|1, m+1, r);
}

int main() {
	scanf("%d %d", &n, &m);
	coor.emplace_back(-1);
	while(m--) {
		int met, a, b;
		scanf("%d %d", &met, &a);
		coor.emplace_back(a);
		if(met) scanf("%d", &b), coor.emplace_back(b);
		V.emplace_back(met, a, b);
	}
	sort(coor.begin(), coor.end());
	coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
	for(auto x : V) {
		if(x.a) update(get(x.b), get(x.c));
		else printf("%s\n", cans[idx[query(get(x.b))]]);
	}
}