#include <bits/stdc++.h>
#define long long long
using namespace std;

int move(int &from, int to, long &x) {
	int l = from, r = to;
	if(l < r) swap(l, r);
	long rm = (1LL << l) - (1LL << r);
	x &= ~rm;
	from = to;
	return l - r;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int k, n;
	scanf("%d %d", &k, &n);
	while(n--) {
		long a, b;
		int at, to;
		scanf("%lld %d %lld %d", &a, &at, &b, &to);
		long x = a ^ b;
		int d = 0, cnt = 0;
		while(x) {
			int l = sizeof(long) * 8 - __builtin_clzll(x);
			int r = __builtin_ctzll(x);
			if (at > l)
                d += move(at, l, x);
            else if (at < r)
                d += move(at, r, x);
            else if (at == l)
                d += move(at, r, x);
            else if (at == r)
                d += move(at, l, x);
            else if (at > to)
                d += move(at, l, x);
            else
                d += move(at, r, x);
		}
		d += move(at, to, x);
		printf("%d\n", d);
	}
}