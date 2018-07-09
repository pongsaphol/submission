#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 17;

int n, m, A[MAXN << 1], ans[MAXN];
bool t[31][MAXN << 1], lz[31][MAXN];

template<typename T>
void travel(int x, int y, int cc, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[cc][p]) {
		t[cc][p] = true;
		if(l != r) lz[cc][p << 1] = lz[cc][p << 1 | 1] = true;
		lz[cc][p] = false;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, cc, f, p << 1, l, m), travel(x, y, cc, f, p << 1 | 1, m + 1, r);
	t[cc][p] = (t[cc][p << 1] && t[cc][p << 1 | 1]);
}

void update(int x, int y, int cc) {
	travel(x, y, cc, [&](int p, int l, int r) {
		t[cc][p] = true;
		if(l != r) lz[cc][p << 1] = lz[cc][p << 1 | 1] = true;
	});
}

bool query(int x, int y, int cc) {
	bool st = true;
	travel(x, y, cc, [&](int p, int l, int r) { st &= t[cc][p]; });
	return st;
}

struct data {
	int a, b, c;
	data(int x, int y, int z) { a = x, b = y, c = z;}
};

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	vector<data> V;
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V.emplace_back(a, b, c);
		for(int i = 0; i <= 30; ++i) {
			if(c & (1<<i)) update(a, b, i);
		}
	}
	for(auto x : V) {
		for(int i = 0; i <= 30; ++i) {
			if(!(x.c & (1<<i))) if(query(x.a, x.b, i)) return !printf("NO");
		}
	}
	puts("YES");
	for(int i = 1; i <= n; ++i) 
		for(int j = 0; j < 30; ++j) if(query(i, i, j)) ans[i] |= (1 << j);
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}