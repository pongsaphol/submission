#include <bits/stdc++.h>
#include "gap.h"
#define long long long
using namespace std;

long MX = 1e18;

long findGap(int T, int N) {
	long mn, mx;
	if(T == 2) {
		MinMax(0, MX, &mn, &mx);
		long sz = (mx-mn+N-2) / (N-1);		
		long ans = sz;
		long pv = mn;
		long z = mx;
		long p = mn;
		while(p <= z) {
			MinMax(p, p+sz, &mn, &mx);
			if(mn != -1) {
				ans = max(ans, mn - pv);
				pv = mx;
			}
			p += sz+1;
		}
		return ans;
	} else {
		vector<long> vec;
		long l = 0, r = MX;
		while(vec.size() < N) {
			MinMax(l, r, &mn, &mx);
			if(mn != -1) vec.emplace_back(mn);
			if(mn != mx) vec.emplace_back(mx);
			l = mn+1, r = mx-1;
		}
		sort(vec.begin(), vec.end());
		long ans = 0;
		for(int i = 1; i < N; ++i) ans = max(ans, vec[i] - vec[i-1]);
		return ans;
	}
}
