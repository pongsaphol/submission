#include <bits/stdc++.h>
using namespace std;

int n, m, X[] = {0, 0, -1, 1}, Y[] = {1, -1, 0, 0};
char A[1005][1005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(A[i][j] == 'S') {
			for(int k = 0; k < 4; ++k) {
				if(A[i+X[k]][j+Y[k]] == '.') A[i+X[k]][j+Y[k]] = 'D';
				if(A[i+X[k]][j+Y[k]] == 'W') return !printf("No");
			}
		}
	}
	puts("Yes");
	for(int i = 1; i <= n; ++i) printf("%s\n", A[i] + 1);
}