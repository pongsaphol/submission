#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int ptr = 1, t[30*MAXN], sl[30*MAXN], sr[30*MAXN];

int update(int x, int v, int lv = 30, int p = 1) {
	if(p == 0) p = ++ptr;
	if(lv < 0) return p;
	if(x&(1<<lv)) t[sl[p] = update(x, v, lv-1, sl[p])] += v;
	else t[sr[p] = update(x, v, lv-1, sr[p])] += v;
	return p;
}

int query(int x, int lv = 30, int p = 1) {
	if(lv < 0) return x;
	if(x&(1<<lv)) {
		if(t[sr[p]]) return query(x, lv-1, sr[p]);
		else return query(x^(1<<lv), lv-1, sl[p]);
	} else {
		if(t[sl[p]]) return query(x^(1<<lv), lv-1, sl[p]);
		else return query(x, lv-1, sr[p]);
	}
}

int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	update(0, 1);
	while(n--) {
		char met; int x;
		scanf(" %c %d", &met, &x);
		if(met == '+') update(x, 1);
		if(met == '-') update(x, -1);
		if(met == '?') printf("%d\n", query(x));
	}
}
