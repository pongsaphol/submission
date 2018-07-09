#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, l, u, H[N];
bool t[N<<1];

void upd(int x) { for(t[x += N] = true; x != 1; x >>= 1) t[x>>1] = true; }
bool que(int l, int r) {
	bool st = false;
	for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) st |= t[l++];
		if(r & 1) st |= t[--r];
	}
	return st;
}

bool f(int m) {
	memset(t, 0, sizeof t);
	upd(0);
	set<int> S;
	for(int i = 1; i < l; ++i) if(H[i] >= m) S.emplace(i);
	for(int i = l; i <= n; ++i) {
		if(H[i] >= m) S.emplace(i);
		if(i - u > 0) if(H[i - u] >= i) S.erase(i - u);
		if(S.empty()) continue;
		int ret = *S.rbegin();
		if(que(max(0, i - u), min(i - l, ret - 1))) upd(i); 
	}
	return que(n, n);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &l, &u);
	for(int i = 1; i <= n; ++i) scanf("%d", H+i);
	int l = -1, r = 1e9;
	while(l < r) {
		int m = (l + r + 1) >> 1;
		if(f(m)) l = m;
		else r = m-1;
	}
	printf("%d\n", l);
}