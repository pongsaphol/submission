#include "bubblesort2.h"
#include <bits/stdc++.h>
#define _native_
using namespace std;

int n, m;
vector<int> now;

int count(int l = 0, int r = n-1) {
	if(l == r) return 0;
	int m = l + r >> 1;
	int sum = count(l, m) + count(m+1, r);
	vector<int> ret;
	int p1 = l, p2 = m+1;
	while(p1 <= m && p2 <= r) {
		if(now[p1] <= now[p2]) ret.emplace_back(now[p1++]);
		else ret.emplace_back(now[p2++]), sum += m - p1 + 1;
	}
	while(p1 <= m) ret.emplace_back(now[p1++]);
	while(p2 <= r) ret.emplace_back(now[p2++]);
	for(int i = l; i <= r; ++i) now[i] = ret[i-l];
	return sum;
}

vector<int> countScans(vector<int> A, vector<int> X, vector<int> V){
#ifdef _native_
	n = A.size(), m = X.size();
	vector<int> ans;
	for(int z = 0; z < m; ++z) {
		A[X[z]] = V[z];
		now.clear();
		for(auto x : A) now.emplace_back(x);
		for(int i = 0; i <= n; ++i) {
			bool st = true;
			for(int j = 1; j < n; ++j) if(now[j-1] > now[j]) swap(now[j-1], now[j]), st = false;
			if(st) {
				ans.emplace_back(i);
				break;
			}
		}
	}
	return ans;
#endif
}