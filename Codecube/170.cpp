#include <bits/stdc++.h>
using namespace std;

int n, k, A[1005], B[1005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d %d", A+i, B+i);
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= min(n, i+k); ++j) {
			int dip = min(A[i], B[j]);
			A[i] -= dip;
			B[j] -= dip;
		}
		for(int j = i; j <= min(n, i+k); ++j) {
			int dip = min(B[i], A[j]);
			B[i] -= dip;
			A[j] -= dip;
		}
	}
	bool st = true;
	for(int i = 1; i <= n; ++i) if(A[i] || B[i]) st = false;
	puts(st ? "YES" : "NO");
}