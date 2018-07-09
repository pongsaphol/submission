#include <bits/stdc++.h>
using namespace std;

int n, A[100005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) {
		int a = i, b = A[i], c = A[A[i]];
		if(A[c] == a && a != b && b != c && a != c) return !printf("YES");
	}
	puts("NO");
}