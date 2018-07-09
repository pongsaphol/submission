#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int low[MAXN], sieve[MAXN], l2[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	for(int i = 1; i <= MAXN-5; ++i) 
		for(int j = i; j <= MAXN-5; j += i) {
			sieve[j]++;
			if(sieve[i] == 2 and i != j) low[j] = i;
		}
	for(int i = 1; i <= MAXN-5; ++i) {
		if(low[i] != 0) l2[i] = (i / low[i] - 1) * low[i] + 1;
		else l2[i] = i;
	}
	int n; scanf("%d", &n);
	int mn = 1e9;
	for(int i = l2[n]; i < n; ++i) {
		mn = min(mn, l2[i]);
	}
	printf("%d\n", mn);
}