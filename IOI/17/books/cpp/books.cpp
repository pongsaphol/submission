#include <bits/stdc++.h>
#include "books.h"
#define long long long 
using namespace std;
 
const int N = 1e6+5;
 
long ans = 0;
int n, x, y;
int id[N], L[N], R[N], ptr;
bool check[N];
 
void extend(int &l, int &r) {
	int ll = min(L[id[l]], L[id[r]]);
	int rr = max(R[id[l]], R[id[r]]);
	while(ll < l || r < rr) {
		if(ll < l) l--;
		else r++;
		ll = min(ll, min(L[id[l]], L[id[r]]));
		rr = max(rr, max(R[id[l]], R[id[r]]));
	}
}
 
long minimum_walk(vector<int> p, int s) {
	n = p.size();
	x = y = s;
	for(int i = 0; i < n; ++i) ans += abs(i - p[i]);
	for(int i = 0; i < n; ++i) if(!check[i]) {
		id[i] = ++ptr, check[i] = true;
		L[ptr] = R[ptr] = i;
		int u = i;
		while(p[u] != i) {
			id[u = p[u]] = ptr;
			check[u] = true;
			R[ptr] = max(R[ptr], u);
		}
		if(i != p[i]) x = min(x, L[ptr]), y = max(y, R[ptr]);
	}
	int l = s, r = s;
	while(x < l || r < y) {
		extend(l, r);
		int al = l, ar = r;
		int bl = l, br = r;
		long ca = 0, cb = 0;
		while(x < al && ar == r) ca += 2, extend(--al, ar);
		while(bl == l && br < y) cb += 2, extend(bl, ++br);
		if(ar != r && bl != l) ans += min(ca, cb);
		else ans += ca + cb;
		l = min(al, bl), r = max(ar, br);
	}
	return ans;
}