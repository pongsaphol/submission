#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6+5;

int n, p, q, t1[N<<1], t2[N<<1]; // max, min

int quemax(int l, int r) {
	int mx = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mx = max(mx, t1[l++]);
		if(r & 1) mx = max(mx, t1[--r]); 
	}
	return mx;
}

int quemin(int l, int r) {
	int mn = 1e9;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mn = min(mn, t2[l++]);
		if(r & 1) mn = min(mn, t2[--r]);
	}
	return mn;
}

int main() {
	scanf("%d %d %d", &n, &p, &q);
	for(int i = 0; i < n; ++i) scanf("%d", t1+n+i), t2[n+i] = t1[n+i];
	for(int i = n-1; i != 0; --i) {
		t1[i] = max(t1[i << 1], t1[i << 1 | 1]);
		t2[i] = min(t2[i << 1], t2[i << 1 | 1]);	
	}
	int p1 = 0, p2 = 0;
	ll sum = 0;
	for(int i = 0; i < n; ++i) {
		while(quemax(p1, i) - quemin(p1, i) > q) p1++;
		while(quemax(p2, i) - quemin(p2, i) >= p) p2++;	
		if(quemax(p1, i) - quemin(p1, i) <= q and quemax(p2, i) - quemin(p2, i) < p) sum += p2-p1;
	}
	printf("%lld\n", sum);
}