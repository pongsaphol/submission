#include <bits/stdc++.h>
#define long long long
#define iiii tuple<long, long, long, long>
using namespace std;

const int N = 1e5;
const int B = 400;
const int MXN = 1<<17;
const long INF = 1e18;

int T, n, q, chk[MXN<<1];
iiii t[MXN<<1];

long get(iiii x, long z) {
long a, b, c, d; tie(a, b, c, d) = x;
	return z * z * z * a + z * z * b + z * c + d;
}

void update(iiii x, int s, int p = 1, int l = B, int r = N) {
	if(chk[p] != s) { t[p] = x, chk[p] = s; return; }
	if(get(t[p], l) < get(x, l) && get(t[p], r) < get(x, r)) return;
	if(get(t[p], l) > get(x, l) && get(t[p], r) > get(x, r)) return void(t[p] = x);
	if(l == r) return;
	int m = (l + r) >> 1;
	if(get(t[p], l) > get(x, l)) swap(t[p], x);
	if(get(t[p], m) > get(x, m)) swap(t[p], x), update(x, s, p<<1, l, m);
	else update(x, s, p<<1|1, m+1, r);
}

long query(int x, int s, int p = 1, int l = B, int r = N) {
	if(chk[p] != s) return INF;
	long ret = get(t[p], x);
	if(l == r) return ret;
	int m = (l + r) >> 1;
	return min(ret, x <= m ? query(x, s, p<<1, l, m) : query(x, s, p<<1|1, m+1, r));
}

void solve(int x) {
	scanf("%d", &n);	
	vector<long> getMin(B, INF);
	for(int i = 0, a, b, c, d; i < n; ++i) {
		scanf("%d %d %d %d", &d, &c, &b, &a);
		iiii ret = tie(a, b, c, d);
		for(int i = 0; i < B; ++i) getMin[i] = min(getMin[i], get(ret, i));
		update(ret, x);
	}
	scanf("%d", &q);
	for(int i = 0, a; i < q; ++i) {
	 	scanf("%d", &a);
		printf("%lld\n", a < B ? getMin[a] : query(a, x));
	}
}

int main() {
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) solve(i);	
}
