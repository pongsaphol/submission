#include "hollib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int n, a1[N], a2[N];

void solve() {
	n = hol_init();
	int l, r, l1, l2, l3, r1, r2, r3;
	while(l < r) {
		int sz = r-l+1;
		int z = sz / 3;
		if(sz % 3 == 0) {
			l1 = l; r1 = l1+z-1; l2 = r1+1; r2 = l2+z-1; l3 = r2+1, r3 = r;
		} else {
			l1 = l; r1 = l1+z; l2 = r1+1; r2 = l2+z; l3 = r2+1, r3 = r;
		}
		for(int i = l1; i <= r1; ++i) a1[i-l1] = i;
		for(int i = l2; i <= r2; ++i) a2[i-l2] = i;
		int met = hol_weight(r1-l1+1, a1, r2-l2+1, a2);
		if(met == -1)
	}
}

int main() {
	int T = hol_init_all();
	while(T--) solve();
}