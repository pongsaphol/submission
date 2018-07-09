#include <bits/stdc++.h>
#define long long long
#define pii pair<long, int>
#define x first
#define y second 
using namespace std;

const int N = 1e5+5;
int n, k, A[N];
long ans, qs[N];

int main() {
	scanf("%d %d", &n, &k);
	set<int> S;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		if(A[i] > k) {
			i--;
			n--;
			continue;
		}
		qs[i] = qs[i-1] + A[i], S.emplace(A[i]);
	}
	if(S.size() == n and qs[n] <= k) ans = qs[n];
	for(int i = 1; i <= 500; ++i) {
		vector<long> dp(n+1, 0);
		vector<int> pos(k+1, 0);
		deque<pii> Q;
		Q.push_back(pii(0, 0));
		for(int j = 1, ptr = 0; j <= n; ++j) {
			if(pos[A[j]]) ptr = max(ptr, pos[A[j]]);
			pos[A[j]] = j;
			while(qs[j] - qs[ptr] > k) ptr++;
			while(!Q.empty() and Q.front().y < ptr) Q.pop_front();
			dp[j] = max(dp[j-1], Q.front().x + qs[j]);
			while(!Q.empty() and Q.back().x < (dp[j-1] - qs[j])) Q.pop_back();
			Q.push_back(pii(dp[j-1] - qs[j], j));
		}
		ans = max(ans, dp[n-1]);
		for(int j = 1; j < n; ++j) swap(A[j], A[j+1]);
		for(int j = 1; j <= n; ++j) qs[j] = qs[j-1] + A[j];
	}
	printf("%lld\n", ans);
}