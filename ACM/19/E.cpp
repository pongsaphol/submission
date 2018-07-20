#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, cnt, A[N];

int main() {
	multiset<int> S;
	scanf("%d", &n);
	vector<int> ans;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		if(A[i] > 0) S.emplace(A[i]);
		if(A[i] < 0) {
			if(S.find(-A[i]) != S.end()) S.erase(S.find(-A[i]));
			else cnt--, ans.emplace_back(-A[i]);
		}
		if(!A[i]) cnt++;
		if(cnt == -1) return !printf("No\n");
	}
	puts("Yes");
	while(cnt--) ans.emplace_back(1);
	for(int x : ans) printf("%d ", x);
}
