#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int ans[7];

int main() {
	freopen("r", "r", stdin);
	long double x;
	cin >> x;
	for(int k = 1; k <= 100000	00; ++k) {
		int L = k, R = 5*k, mid;
		while(L < R) {
			mid = (L+R)/2;
			long double z = (long double)mid/k;
			if(z >= x) R = mid;
			else L = mid + 1;
		}
		long double z = ((long double)R/k) - x;
		// printf("%Lf\n", z);
		if(z <= 1e-10) {
			k--;
			for(int i = 5; i >= 1; --i) {
				while(R-i >= k) {
					k--;
					R -= i;
					ans[i]++;
					// printf("%d %d %d\n", R, i, k);
					if(R == 0) break;
				}
			}
			for(int i = 1; i <= 5; ++i) printf("%d ", ans[i]);
			return 0;
		}
	}
}