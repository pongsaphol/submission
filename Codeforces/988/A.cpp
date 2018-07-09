#include <bits/stdc++.h>
#pragma once
using namespace std;

int A[105];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	set<int> S;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		S.emplace(A[i]);
	}
	if(S.size() < k) return !printf("NO");
	puts("YES");
	S.clear();
	for(int i = 1; i <= n; ++i) {
		if(S.find(A[i]) == S.end()) printf("%d ", i), k--;
		S.emplace(A[i]);
		if(k == 0) break;
	}
}