#include <bits/stdc++.h>
using namespace std;

bool ans[105][105];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	if(k % 2 == 0) {
		for(int i = 2; i < n; ++i) for(int j = 2; j < 4; ++j) if(--k >= 0) ans[j][i] = 1;
	} else if(k) {
		for(int j = 2; j < 4; ++j) for(int i = 2; i <= n/2; ++i) {
			if(k > 1) {
				k-=2;
				ans[j][i] = ans[j][n-i+1] = 1; 
			}
		}
		if(k) ans[2][(n+1) >> 1] = 1;
	}
	puts("YES");
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%c", ans[i][j] ? '#' : '.');
		}
		puts("");
	}
}