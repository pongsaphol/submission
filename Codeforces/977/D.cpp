#include <bits/stdc++.h>
#define long long long
using namespace std;

map<int, set<long> > M;

int n;

int main() {
	scanf("%d", &n);
	while(n--) {
		long ret; scanf("%lld", &ret);
		long now = ret, cnt = 0;
		while(now % 3 == 0) now /= 3, cnt++;
		M[cnt].emplace(ret);
	}
	for(auto it = M.rbegin(); it != M.rend(); ++it) {
		for(auto x : it->second) printf("%lld ", x);
	}
}