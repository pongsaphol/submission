#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, A[N];

int main() {
	set<int> S;
	scanf("%d", &n);
	int cnt = -1;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		cnt += (A[i] != A[i-1]);
		S.emplace(A[i]);	
	}	
	set<pii> Ss;
	for(int i = 1; i < n; ++i) {
		auto it = S.upper_bound(A[i]);
		if(it != S.end() && A[i+1] == *it) Ss.emplace(A[i], A[i+1]);
	}
	return !printf("%d\n", cnt - (int)Ss.size());
}
