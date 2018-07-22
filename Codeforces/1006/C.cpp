#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 2e5+5;

int n;
long A[N], qs[N];

int main() {
	scanf("%d", &n);
	multiset<long> S;
	for(int i = 1; i <= n; ++i) scanf("%lld", A+i), S.emplace(qs[i] = qs[i-1] + A[i]);
	long sum = 0, mx = 0;
	for(int i = n; i; --i) {
		sum += A[i];
		S.erase(S.find(qs[i]));
		if(S.find(sum) != S.end()) mx = sum;
	}	
	printf("%lld\n", mx);
}
