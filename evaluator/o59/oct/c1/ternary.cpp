#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define long long long
using namespace std;

int n, A[105], B[105];
long dp[105][105][105], MOD = 1e9+7;
unordered_map<int,int> M;

void read() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	for(int i = 0; i < n; ++i) {
		scanf("%d", B+i);
		M[B[i]] = i;
	}
}

long solve(int x = 0, int y = 0, int l = n) {
	long &now = dp[x][y][l];
	if(now != -1) return now;
	if(l == 0) return now = 1;
	if(l == 1 && A[x] == B[y]) return now = 1;
	if(l == 1) return now = 0;
	int idx = M[A[x]];
	if(idx > y + l || idx < y) return now = 0;
	int sz = idx - y;
	int rur = l - sz - 1;
	now = 0;
	for(int i = 0; i <= rur; ++i) {
		long cache = solve(x + sz + 1, y + sz + 1, i)*
		solve(x + sz + 1 + i, y + sz + 1 + i, rur - i);
		cache %= MOD;
		cache *=  solve(x + 1, y, sz);
		now += cache;
		now %= MOD;
	}
	return now;
}

int main() {
	memset(dp, -1, sizeof dp);
	read();
	printf("%lld\n", solve());
}