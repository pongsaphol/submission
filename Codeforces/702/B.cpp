#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	map<int, int> M;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		M[A[i]]++;
	}
	long long sum = 0;
	for(int i = 1; i <= n; ++i) {
		M[A[i]]--;
		for(int j = 1; j <= 30; ++j) sum += M[(1<<j)-A[i]];
	}
	printf("%lld\n", sum);
}