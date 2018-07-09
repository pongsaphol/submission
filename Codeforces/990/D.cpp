#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, a, b;
bool adj[N][N];

int main() {
	scanf("%d %d %d", &n, &a, &b);
	if(n == 1 and a == 1 and b == 1) return !printf("YES\n0");
	if(a != 1 and b != 1) return !printf("NO");
	if(a == 1 and b == 1 and n <= 3) return !printf("NO");
	puts("YES"); 
	int want = a < b ? b : a;
	if(a == 1 and b == 1) for(int i = 1; i < n; ++i) adj[i][i+1] = adj[i+1][i] = 1;
	else for(int j = want+1; j <= n; ++j) adj[j][1] = adj[1][j] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) printf("%d", i == j ? 0 : ((a < b) ^ adj[i][j]));
		puts("");
	}
}