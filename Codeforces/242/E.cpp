#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1<<17;

struct data {
	int A[25];
	void add(int x, int sz) {
		for(int i = 0; i < 20; ++i) if(x&(1<<i)) A[i] = sz - A[i];
	}
	long calc() {
		long sum = 0;
		for(int i = 0; i < 20; ++i) sum += (long)(1<<i)*A[i];
		return sum;
	}
	friend inline data operator+(const data &a, const data &b) {
		data ret;
		for(int i = 0; i < 20; ++i) ret.A[i] = a.A[i] + b.A[i];
		return ret;
	}
};

int n, m, A[MAXN], lz[MAXN<<1];
data t[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p].add(A[l], 1);
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p].add(lz[p], r-l+1);
		if(l != r) {
			lz[p<<1] ^= lz[p];
			lz[p<<1|1] ^= lz[p];
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int x, int y, int v) {
	travel(x, y, [&](int p, int l, int r) {
		t[p].add(v, r-l+1);
		if(l != r) {
			lz[p<<1] ^= v;
			lz[p<<1|1] ^= v;
		}
	});
}

long query(int x, int y) {
	long sum = 0;
	travel(x, y, [&](int p, int l, int r) {
		sum += t[p].calc();
	});
	return sum;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();
	scanf("%d", &m);
	while(m--) {
		int met, a, b, c;
		scanf("%d %d %d", &met, &a, &b);
		if(met == 1) printf("%lld\n", query(a, b));
		else {
			scanf("%d", &c);
			update(a, b, c);
		}
	}
}