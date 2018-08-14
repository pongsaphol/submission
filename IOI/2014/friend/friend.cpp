#include "friend.h"
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

pii dp[N];

int findSample(int n, int cof[], int host[], int pro[]) {
	for(int i = 0; i < n; ++i) dp[i].x = cof[i];
	for(int i = n-1; i; --i) {
		pii &v = dp[host[i]], &u = dp[i];
		if(pro[i] == 0) v = pii(v.x + u.y, max(v.y + u.x, v.y + u.y));
		if(pro[i] == 1) v = pii(max({v.x + u.y, u.x + v.y, v.x + u.x}), v.y + u.y);
		if(pro[i] == 2) v = pii(max(v.x + u.y, v.y + u.x), v.y + u.y);
	}
	return max(dp[0].x, dp[0].y);
}

