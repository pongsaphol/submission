#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, A[1005], F[1005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		A[i] += A[i-1];
	}
	for(int i = 1; i <= n; ++i) F[i] = 1e9+1;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			F[j-i] = min(F[j-i], A[j] - A[i]);
		}
	}
	while(m--) {
		int x;
		scanf("%d", &x);
		int L = 0, R = n;
		while(L < R) {
			int mid = (L+R+1)/2;
			if(F[mid] <= x) L = mid;
			else R = mid-1;
		}
		printf("%d\n", L);
	}
}