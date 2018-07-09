#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<17;

int n, m, t[MAXN<<1];

int f(int x) {
	return (int)log2(x);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	n = (1<<n);
	for(int i = 0; i < n; ++i) scanf("%d", t+i+n);
	for(int i = n-1; i != 0; --i) 
		if((f(i)%2) ^ (f(n)%2)) t[i] = t[i<<1] | t[i<<1|1];
		else t[i] = t[i<<1] ^ t[i<<1|1];
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		for(t[a += n-1] = b; a != 1; a >>= 1) 
			if((f(a>>1)%2) ^ (f(n)%2)) t[a>>1] = t[a] | t[a^1];
			else t[a>>1] = t[a] ^ t[a^1];
		printf("%d\n", t[1]);
	}
}