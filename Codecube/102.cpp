#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;

int n, p, t[N<<1], lz[N<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = 10000;
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
}

void pushlazy(int p, int l, int r) {
	if(lz[p]) {
		t[p] -= lz[p];
		if(l != r) {
			lz[p << 1] += lz[p];
			lz[p << 1 | 1] += lz[p];
		}
		lz[p] = 0;
	}
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	pushlazy(p, l, r);
	if(x <= l and r <= y) return f(p, l, r);
	if(x > r or l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p << 1, l, m), travel(x, y, f, p << 1 | 1, m+1, r);
}

void upd(int l, int r, int d) {
	travel(l, r, [&](int p, int l, int r) {
		lz[p] += d;
		pushlazy(p, l, r);
	});
}

void update(int l, int r, int d) {
	if(l < 1) {
		upd(l+n, n, d), upd(1, r, d);
	} else if(r > n) {
		upd(l, n, d), upd(1, r-n, d);
	} else {
		upd(l, r, d);
	}
}

int query(int idx) {
	int ans = -1;
	travel(idx, idx, [&](int p, int l, int r) {
		ans = t[p];
	});
	return ans;	
}

int main() {
	scanf("%d %d", &n, &p);
	build();
	while(p--) {
		int a, k, d, q;
		scanf("%d %d %d %d", &a, &k, &d, &q);
		update(a - k, a, d), update(a+1, a+k, d);
		while(q--) {
			int ret; scanf("%d", &ret);
			int ans = query(ret);
			printf("%d ", ans < 0 ? 0 : ans);
		}
		puts("");
	}
}