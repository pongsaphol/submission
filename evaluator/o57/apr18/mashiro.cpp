#include <bits/stdc++.h>
#define long long long
#define x first
#define y second
using namespace std;

const int MAXN = 2e6+5;

int n, m, par[MAXN], cnt[MAXN];

long pown(long x, int v) {
	assert(v >= 0);
	long sm = 1;
	for(; v; v >>= 1) {
		if(v&1) sm = (sm * x) % m;
		x = (x * x) % m;
	}
	return sm;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 2; i <= 2*n; ++i) {
		if(i > n) ++cnt[i];
		else --cnt[i];
		if(par[i] == 0) par[i] = i;
		for(int j = i+i; j <= 2*n; j += i) {
			if(par[j] == 0) par[j] = j/i;
		}
	}
	long sum = 1;
	for(int i = 2*n; i > 1; --i) {
		if(par[i] != i) {
			cnt[i / par[i]] += cnt[i];
			cnt[par[i]] += cnt[i];
		} else sum = (sum*pown(i, cnt[i])) % m;
	}
	printf("%lld", (sum * sum) % m);
}