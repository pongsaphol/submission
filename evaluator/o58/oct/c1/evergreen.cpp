#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 1e3+5;

long k;
int n, A[N];

long f(int m) {
	long sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += (m + 1ll) * (m + 1ll);
		for(int j = i + 1; j <= n; ++j) {
			if((A[j] - A[i] + 1) / 2 <= m) {
				// I will delete it !!!
				if((A[j] - A[i]) % 2) {
					int z = (A[j] - A[i] + 1) >> 1;
					sum -= m + 1 - z + (m + 1ll - z) * (m + 1ll - z);
				} else {
					int z = (A[j] - A[i]) >> 1;
					sum -= (m + 1ll - z) * (m + 1ll - z);
				}
			}
		}
	}
	return sum;
}

int main() {
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	sort(A + 1, A + n + 1);
	// find the minimum day that >= k
	int l = 0, r = 1e9;
	while(l < r) {
		int m = (l + r) >> 1;
		if(f(m) >= k) r = m;
		else l = m + 1;
	}
	for(int i = 0; i <= 10; ++i) printf("%d %lld\n", i, f(i));
	printf("%d\n", r);
}