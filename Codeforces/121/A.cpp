#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int pw(int x) {
	int sn = 1;
	for(int i = 0; i < x; ++i) sn *= 10;
	return sn;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int a, b;
	scanf("%d %d", &a, &b);
	vector<long> V;
	for(int len = 1; len <= 9; ++len) for(int j = 0; j < (1<<len); ++j) {
		int sum = 0;
		for(int k = 0; k < len; ++k) {
			if(j & (1 << k)) sum += 7 * pw(k);
			else sum += 4 * pw(k);
		}
		V.emplace_back(sum);
	}
	V.emplace_back(4444444444);
	long sum = 0;
	while(a <= b) {
		long ret = *lower_bound(all(V), a);
		if(ret <= b) {
			sum += 1ll * ret * (ret - a + 1);
			a = ret + 1;
		} else {
			sum += 1ll * ret * (b - a + 1);
			a = b + 1;
		}
	}
	printf("%lld\n", sum);
}