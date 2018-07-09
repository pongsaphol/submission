#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int n, A[MAXN], ptr = 1;

struct {
	int l, r, cnt;
} d[20000000];

int ins(int val, int lv = 29, int p = 1) {
	if(p == 0) p = ++ptr;
	if(lv == -1) {
		d[p].cnt++;
		d[p].l = val;
		return p;
	}
	if(val & (1<<lv)) d[p].l = ins(val, --lv, d[p].l);
	else d[p].r = ins(val, --lv, d[p].r);
	return p;
}

bool find(int &val, int lv = 29, int p = 1) {
	if(lv == -1) {
		d[p].cnt--;
		// printf("%d\n", d[p].l);
		return d[p].cnt == 0;
	}
	bool st1 = false, st2 = false;
	if(!d[p].l && !d[p].r) {
		// printf("-->%d\n", lv);
	}
	if(val&(1<<lv)) {
		if(d[p].l) {
			val ^= (1 << lv);
			st1 = find(val, --lv, d[p].l);
		}else st2 = find(val, lv-1, d[p].r);
	} else {
		if(d[p].r) st2 = find(val, lv-1, d[p].r);
		else {
			val ^= (1<<lv);
			st1 = find(val, lv-1, d[p].l);
		}
	}
	bool st = false;
	if(st1) d[p].l = 0, st = true;
	if(st2) d[p].r = 0, st = true;
	if(d[p].l) st = false; if(d[p].r) st = false;
	// printf("%d %d\n", lv, st);
	return st;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		ins(now);
	}
	for(int i = 1; i <= n; ++i) {
		find(A[i]);
		printf("%d ", A[i]);
	}
}