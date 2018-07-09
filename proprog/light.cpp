#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1<<17;

int n, m, t[MAXN<<1], lazy[MAXN<<1];

void update(int x, int y, int l = 1, int r = n, int ptr = 1) {
	int sz = r-l+1;
	if(lazy[ptr] != 0) {
		if(lazy[ptr] % 2) {
			t[ptr] = sz - t[ptr];
			if(l != r) {
				lazy[ptr<<1]++;
				lazy[ptr<<1|1]++;
			}
		}
		lazy[ptr] = 0;
	}
	if(x > r || l > y) return;
	if(x <= l && r <= y) {
		t[ptr] = sz - t[ptr];
		if(l != r) {
			lazy[ptr<<1]++;
			lazy[ptr<<1|1]++;
		}
		return;
	}
	int mid = (l+r)/2;
	update(x, y, l, mid, ptr<<1);
	update(x, y, mid+1, r, ptr<<1|1);
	t[ptr] = t[ptr<<1] + t[ptr<<1|1];
}

int query(int x, int y, int l = 1, int r = n, int ptr = 1) {
	int sz = r-l+1;
	if(lazy[ptr] != 0) {
		if(lazy[ptr] % 2) {
			t[ptr] = sz - t[ptr];
			if(l != r) {
				lazy[ptr<<1]++;
				lazy[ptr<<1|1]++;
			}
		}
		lazy[ptr] = 0;
	}
	if(x > r || l > y) return 0;
	if(x <= l && r <= y) return t[ptr];
	int mid = (l+r)/2;
	return query(x, y, l, mid, ptr<<1) + query(x, y, mid+1, r, ptr<<1|1);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	while(m--) {
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if(!x) update(a, b);
		else printf("%d\n", query(a, b));
	}
}