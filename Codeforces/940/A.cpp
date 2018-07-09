#include <bits/stdc++.h>
using namespace std;

int n, m, A[105];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	sort(A+1, A + n + 1);
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(A[j] - A[i] <= m) mx = max(mx, j-i+1);
		}
	}
	cout << n-mx;
}