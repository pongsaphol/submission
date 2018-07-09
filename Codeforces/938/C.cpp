#include <bits/stdc++.h>
#define long long long
using namespace std;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		long x;
		scanf("%lld", &x);
		bool ans = true;
		for(long i = 1; i <= 100000; ++i) {
			long val = (i*i) - x;
			// if(x == 99999999 && i == 10000) printf("->");
			if(val > 0) {
				long ret = sqrt(val);
				if(ret*ret == val) {
					long zz = i / ret;
					for(long m = zz - 2; m <= zz + 2; ++m) {
						if(m < 1 || m > i) continue;
						long z = i*i - (i / m) * (i / m);
						if(z == x) {
							printf("%lld %lld\n", i, m);
							ans = false;
							break;
						}
					}
					if(!ans) break;
				}
			}
		}
		if(ans) puts("-1");
	}
}