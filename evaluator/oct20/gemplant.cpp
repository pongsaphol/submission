#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<18;

int n, m, t[MAXN<<1];

void update(int x, int v) {
	for(t[x += n] += v; x != 1; x >>= 1) t[x>>1] = t[x] + t[x^1]; 
}

int query(int l, int r) {
	int sum = 0;
	for(l += n, r += n+1; l < r; l >>=1, r >>= 1) {
		if(l&1) sum += t[l++];
		if(r&1) sum += t[--r];
	}
	return sum;
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) update(c-1, b);
		else printf("%d\n", query(b-1, c-1));
	}
}
