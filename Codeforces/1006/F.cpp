#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
long k, A[25][25];
map<long, long> M[25][25];


int main() {
	scanf("%d %d %lld", &n, &m, &k);
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) scanf("%lld", &A[i][j]);
	M[1][1][A[1][1]] = 1;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if((i != 1 || j != 1) && (i + j <= 20)){
		for(auto x : M[i-1][j]) M[i][j][x.x ^ A[i][j]] += x.y; 
		for(auto x : M[i][j-1]) M[i][j][x.x ^ A[i][j]] += x.y; 
	}
	long sum = 0;
	if(n + m <= 20) return !printf("%lld\n", M[n][m][k]);
	M[n][m][A[n][m] ^ k] = 1;
	for(int i = n; ~i; --i) for(int j = m; ~j; --j) {
		if((i != n || j != m) && M[i][j].empty()) {
			for(auto x : M[i+1][j]) M[i][j][x.x ^ A[i][j]] += x.y; 
			for(auto x : M[i][j+1]) M[i][j][x.x ^ A[i][j]] += x.y; 
		} else if(!M[i][j].empty() && i + j == 20) {
			for(auto x : M[i+1][j]) sum += M[i][j][x.x] * x.y; 
			for(auto x : M[i][j+1]) sum += M[i][j][x.x] * x.y;
		}
	}
	printf("%lld\n", sum);
}
