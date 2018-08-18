#include "mountains.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, dp[N][N];

int maximum_deevs(vector<int> y) {
	n = y.size();
	for(int r = 1; r <= n; ++r) {
		dp[r][r] = dp[r-1][r] = 1;
		int m = r-1, sum = 0;
		for(int l = r-2; l > 0; --l) {
			if(1ll*(m-r)*(y[l-1]-y[r-1]) <= 1ll*(l-r)*(y[m-1]-y[r-1])) {
				sum += dp[l+1][m-1];
				m = l;
			}		
			dp[l][r] = max(dp[l][r-1], dp[l][m-1] + sum + 1);
		}
	}
	return dp[1][n];
}
