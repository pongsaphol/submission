#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e3+5;

int n, m;
long t[4][N][N];

int parity(int x0, int y0) {
    int res = 0;
    if (x0 % 2)
        res += 1;
    if (y0 % 2)
        res += 2;
    return res;
}

void update(int x, int y, long v) {
	int z = parity(x, y);
	for(int i = x; i <= n; i += i & -i) 
		for(int j = y; j <= n; j += j & -j)
			t[z][i][j] ^= v;
}

long query(int x, int y) {
	long v = 0;
	int z = parity(x, y);
	for(int i = x; i; i -= i & -i)
		for(int j = y; j; j -= j & -j)
			v ^= t[z][i][j];
	return v;
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int met, x0, y0, x1, y1;
		long v = 0;
		scanf("%d %d %d %d %d", &met, &x0, &y0, &x1, &y1);
		if(met == 1) {
			printf("%lld\n", query(x1, y1) ^ query(x0-1, y1) ^ query(x1, y0-1) ^ query(x0-1, y0-1));
		} else {
			scanf("%lld", &v);
			update(x0, y0, v);
			update(x0, y1+1, v);
			update(x1+1, y0, v);
			update(x1+1, y1+1, v);
		}
	} 
}