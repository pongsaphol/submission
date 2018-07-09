#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<20;

int n, A[MAXN], t[MAXN<<1];

int cnt0(int l, int r) {
	if(l > r) return 0;
	return (r - l + 1) - (A[r] - A[l-1]);
}

int cnt1(int l, int r) {
	if(l > r) return 0;
	return A[r] - A[l-1];
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m + 1, r);
	t[p] = max(max(t[p<<1] + cnt0(m+1, r), cnt1(l, m) + t[p<<1|1]), cnt1(l, m) + cnt0(m+1, r));
}

struct data {
	int p, l, r;
};

queue<data> Q;

int query(int x, int y, int p = 1, int l = 1, int r = n) {
	if(x == l && r == y) return t[p];
	int m = (l + r) >> 1;
	if(y <= m) return query(x, y, p<<1, l, m);
	if(x > m) return query(x, y, p<<1|1, m+1, r);
	return max(max(cnt1(x, m) + query(m+1, y, p<<1|1, m+1, r), query(x, m, p<<1, l, m) + cnt0(m+1, y)), cnt0(x, m) + cnt1(m+1, y));
}



int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		if(A[i] == 2) A[i] = 1;
		else A[i] = 0;
		A[i] += A[i-1];
	}
	build();
	int mx = 0;
	for(int i = 0; i <= n; ++i) {
		mx = max(mx, cnt0(1, i) + cnt1(i+1, n));
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			// printf("%d %d %d\n", i, j, query(i, j));
			int now = max(mx, cnt0(1, i-1) + query(i, j) + cnt1(j+1, n));
			if(now > mx) {
				mx = now;
				// printf("%d %d %d\n", i, j, query(i, j));
			}
		}
	}
	printf("%d\n", mx);
}