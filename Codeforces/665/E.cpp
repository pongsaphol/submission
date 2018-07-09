#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e6 + 5, L = 30;

long cnt;
int n, k, A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		A[i] ^= A[i-1];
	}
	sort(A, A + n + 1);
	for(int i = 0; i <= n; ++i) {
		for(int j = L-1; j >= 0; --j) {
			if(k - 1 >> j & 1) continue;
			int c = (k - 1 >> j) + 1;
			int d = (A[i] >> j);
			int e = (c << j) ^ (d << j);
			cnt += upper_bound(A, A + n + 1, e + (1 << j) - 1) - lower_bound(A, A + n + 1, e);
		}
	}
	cnt >>= 1;
	printf("%lld\n", cnt);
}