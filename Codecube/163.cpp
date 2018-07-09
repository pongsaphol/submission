#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 1e5;

int n, m, qs[MAXN+5];

void read() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		qs[x]++;
	}
	for(int i = MAXN; i >= 0; --i) {
		qs[i] += qs[i+1];
	}
}

bool f(long x) {
	// printf("%d\n", x);
	long hi = 1, lo = MAXN, k = x;
	for(int i  = MAXN; i >= 1; --i) {
		k -= qs[i];
		if(k < 0) {
			hi = i;
			break;
		} 
	}
	k = x;
	for(int i = 1; i <= MAXN; ++i) {
		k -= n - qs[i];
		if(k < 0) {
			lo = i-1;
			break;
		}
	}
	// printf("%d %d\n", hi, lo);
	if(hi - lo <= m) return true;
	return false;
}

long solve() {
	long L = 0, R = 1e10;
	while(L<R) {
		long mid = (L+R)/2;
		if(f(mid)) R = mid;
		else L = mid+1;
	}
	return R;
}

int main() {
	// freopen("r", "r", stdin);
	read();
	printf("%lld\n", solve());
}