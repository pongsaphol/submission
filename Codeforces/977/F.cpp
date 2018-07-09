#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

map<int, int> pv;
int n, A[N], pre[N], dp[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		dp[i] = 1;
		if(pv[A[i]-1]) {
			dp[i] += dp[pv[A[i]-1]];
			pre[i] = pv[A[i]-1];
		}
		pv[A[i]] = i;
	}
	int idxmx = max_element(dp, dp + N) - dp;
	stack<int> S;
	S.push(idxmx);
	while(S.top()) S.push(pre[S.top()]);
	S.pop();
	printf("%d\n", S.size());
	while(!S.empty()) {
		printf("%d ", S.top());
		S.pop();
	}	
}