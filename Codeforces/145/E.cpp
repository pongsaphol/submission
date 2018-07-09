#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<20;

int n, m, t[4][MAXN<<1]; // 4, 7, 47, 74;
bool lz[MAXN<<1];
char A[MAXN];

void ii(int p) {
	t[0][p] = t[0][p<<1] + t[0][p<<1|1];
	t[1][p] = t[1][p<<1] + t[1][p<<1|1];
	t[2][p] = max(t[0][p<<1] + t[1][p<<1|1], max(t[2][p<<1] + t[1][p<<1|1], t[0][p<<1] + t[2][p<<1|1]));
	t[3][p] = max(t[1][p<<1] + t[0][p<<1|1], max(t[3][p<<1] + t[0][p<<1|1], t[1][p<<1] + t[3][p<<1|1]));
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		if(A[l] == '4') t[0][p] = t[2][p] = t[3][p] = 1;
		if(A[r] == '7')	t[1][p] = t[2][p] = t[3][p] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	ii(p);	
}

void update(int x, int y, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		swap(t[0][p], t[1][p]), swap(t[2][p], t[3][p]);
		if(l != r) {
			lz[p<<1] ^= lz[p];
			lz[p<<1|1] ^= lz[p];
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) {
		swap(t[0][p], t[1][p]), swap(t[2][p], t[3][p]);
		if(l != r) {
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
		return;
	}
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	update(x, y, p<<1, l, m), update(x, y, p<<1|1, m+1, r);
	ii(p);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	scanf("%s", A+1);
	build();
	while(m--) {
		char inp[10];
		scanf("%s", inp);
		if(!strcmp(inp, "count")) printf("%d\n", t[2][1]);
		else {
			int a, b;
			scanf("%d %d", &a, &b);
			update(a, b);
		}
	}
}