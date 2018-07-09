#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 9;

int n, m, A[MAXN][MAXN], tl[MAXN<<1], tr[MAXN<<1], lzl[MAXN<<1], lzr[MAXN<<1];

template<typename T>
void travel(int x, int y, int t[], int lz[], const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] += lz[p];
		if(l != r) {
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, t, lz, f, p<<1, l, m), travel(x, y, t, lz, f, p<<1|1, m+1, r);
	t[p] = max(t[p<<1], t[p<<1|1]); 
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", &A[i][j]);
	// I wll lock
	//		|
	//	   .|
	//-------------
	//		|
	//		|		
	for(int i = 0; i <= n; ++i) {
		for(int j = m; j != 0; --j) {
			travel()
		}
		for(int j = 0; j <= m; ++j) {

		}
	}
}