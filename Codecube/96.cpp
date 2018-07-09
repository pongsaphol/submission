#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;

int n, atk[N];
long qs[3*N];

long get(int l, int r) {
	if(l < 1) l = 1;
	if(r > 3*n) r = 3*n;
	return qs[r] - qs[l-1];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", atk + i);
	for(int i = 1; i <= n; ++i) {
		int ret; scanf("%d", &ret);
		qs[i] = qs[n+i] = qs[n+n+i] = ret;
	}
	for(int i = 1; i <= 3*n; ++i) qs[i] += qs[i-1];
	for(int i = n+1; i <= n+n; ++i) {
		int l = 0, r = (n-1) >> 1;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(get(i-m, i-1) + get(i+1, i+m) <= atk[i-n]) l = m;
			else r = m-1;
		}
		printf("%d ", l << 1);
	}
}