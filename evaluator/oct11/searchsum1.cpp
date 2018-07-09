#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, A[100005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		A[i] += A[i-1];
	}
	while(m--) {
		int x;
		scanf("%d", &x);
		int L = 0, R = n;
		while(L < R) {
			int mid = (L+R+1)/2;
			if(A[mid] <= x) L = mid;
			else R = mid-1;
		}
		printf("%d\n", L);
	}
}