#include <bits/stdc++.h>
using namespace std;

int n, m, chkR[55], chkC[55], chk[55][55];
char A[55][55];

void solve(int x, int y) {
	chk[x][y] = true;
	chkR[x] = true;
	chkC[y] = true;
	for(int i = 1; i <= n; ++i) {
		if(A[i][y] == '#') {
			chk[i][y] = true;
			if(!chkR[i]) solve(i, y);
		}
	}
	for(int i = 1; i <= m; ++i) {
		if(A[x][i] == '#') {
			chk[x][i] = true;
			if(!chkC[i]) solve(x, i);
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(A[i][j] == '#' and !chk[i][j]) {
			solve(i, j);
			for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
				if(A[i][j] == '.' and chkR[i] and chkC[j]) return !printf("No");
			}
			memset(chkR, 0, sizeof chkR);
			memset(chkC, 0, sizeof chkC);
		} 
	}
	puts("Yes");
}