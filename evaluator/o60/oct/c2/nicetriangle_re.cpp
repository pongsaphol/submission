#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 400 , MOD = 29947;

int dp[MAXN][MAXN][MAXN];

void f(int &a, int &b, int &c) {
	if(a < b) swap(a, b);
	if(b < c) swap(b, c);
	if(a < b) swap(a, b);
}

int recur(int a, int b, int c) {
	f(a, b, c);
	int &now = dp[a][b][c];
	if(now != -1) return now;
	if(a == 0 && b == 0 && c == 0) return now = 1;
	now = recur(a-1, b, c);
	for(int i = 1; i <= b; ++i) {
		now += recur(a-1, b-i, c);
		now %= MOD;
	}
	for(int i = 1; i <= c; ++i) {
		now += recur(b, i-1, 0) * recur(a-1, c-i, 0);
		now %= MOD;
	}
	return now;
}

int main() {
	// freopen("r", "r", stdin);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	memset(dp, -1, sizeof dp);
	a--, b--, c--;
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			for(int k = 1)
		}
	}
	printf("%d\n", recur(a-1, b-1, c-1));
}