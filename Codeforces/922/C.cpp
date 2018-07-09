#include <bits/stdc++.h>
using namespace std;


int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	long long n, k;
	cin >> n >> k;
	if(k > 50) return !printf("No");
	set<long long> S;
	for(int i = 1; i <= k; ++i) S.emplace(n%i);
	if(S.size() != k) return !printf("No\n");
	puts("Yes");
}