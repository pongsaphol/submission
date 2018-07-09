#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> S;
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int ret; scanf("%d", &ret);
		S.emplace(ret);
	}
	for(int i = 1; i < n; ++i) {
		if(i % 2 == 0) S.erase(S.begin());
		else {
			auto it = S.end();
			it--;
			S.erase(it);
		}
	}
	printf("%d\n", *S.begin());
}