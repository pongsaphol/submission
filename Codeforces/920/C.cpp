#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

const int MAXN = 1<<18;

int A[MAXN], dp[MAXN];
char in[MAXN];


int main() {
	ref();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	scanf("%s", in+1);
	for(int i = 1; i <= n; ++i) dp[i] = dp[i-1] + (in[i] == '1');
	for(int i = 1; i <= n; ++i) {
		if(A[i] == i) continue;
		if(A[i] < i) if(dp[i-1] - dp[A[i]-1] != i-A[i]) return !printf("NO\n");
		if(A[i] > i) if(dp[A[i]-1] - dp[i-1] != A[i]-i) return !printf("NO\n");
	}
	puts("YES");
}