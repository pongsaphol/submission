#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, A[N], g[N];
int have[N], ans[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) if(!g[i]) {
		for(int j = i+1; j <= n; ++j) {
			long long z = 1ll * A[i] * A[j];
			if(z < 0) continue;
			long long zz = sqrt(z);
			zz = zz * zz;
			if(zz == z) g[j] = i;
		}
		g[i] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		for(int j = i; j <= n; ++j) {
			if(have[g[j]] != i) have[g[j]] = i, ++cnt;
			ans[cnt]++;
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}