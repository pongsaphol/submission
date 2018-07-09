#include <bits/stdc++.h>
using namespace std;

char A[200][200];
int n, m, x[] = {-1, -1, -1, 0, 0, 1, 1, 1}, y[] = {-1, 0, 1, -1, 1, -1, 0, 1} ;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);	
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(A[i][j] != '*') {
		int sum = 0;
		for(int k = 0; k < 8; ++k) if(A[i+x[k]][j+y[k]] == '*') sum++;
		if(!sum and A[i][j] != '.') return !printf("NO");
		if(sum and A[i][j] - '0' != sum) return !printf("NO");
	}
	puts("YES");
}