#include <bits/stdc++.h>
using namespace std;

int n, cnt;
char A[105];
bool st[105];

void dfs(int lv) {
	// printf("do : %d\n", lv);
	if(lv == n) {
		cnt++;
		if(cnt == 2) {
			puts("Yes");
			exit(0);
		}
		return;
	}
	
	if(st[lv]) {
		for(int i = 1; i <= 3; ++i) {
			// if(lv == 2) cout << i << endl;
			if(lv == 0) {
				A[lv] = i;
				dfs(lv+1);
			} else if(i != A[lv-1]) {
				// if(lv == 2)printf("->%d\n", i);
				A[lv] = i;
				dfs(lv+1);
			}
		}
	} else {
		if(lv != 0) if(A[lv] == A[lv-1]) return;
		dfs(lv+1);
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%s", A);
	for(int i = 0; i < n; ++i) {
		if(A[i] == '?') st[i] = true;
		if(A[i] == 'C') A[i] = 1;
		if(A[i] == 'Y') A[i] = 2;
		if(A[i] == 'M') A[i] = 3;
	}
	dfs(0);
	puts("No");
}