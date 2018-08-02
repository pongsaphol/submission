#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

int n, A[5005];

int getNum(int a1, int a2, int a, int b) {
	if(a < b) {
		if(a2 - a1 == b - a) return a - a1;
		return a + a1;
	} else {
		if(a2 - a1 == a - b) return a + a1;
		return a - a1;
	}
}

void solve(int N) {
	n = N;
	A[1] = 0, A[2] = query(1, 2);
	for(int i = 3; i <= n; ++i) A[i] = getNum(query(i-1, i), query(i-2, i), A[i-1], A[i-2]);
	int mn = *min_element(A+1, A+n+1);
	int p1, pn;
	for_each(A+1, A+n+1, [&](int &x) { x = x - mn + 1; });
	for(int i = 1; i <= n; ++i) {
		if(A[i] == 1) p1 = i;
		if(A[i] == n) pn = i;
	}
	if(p1 > pn) for_each(A+1, A+n+1, [&](int &x) { x = n - x + 1; });
	for(int i = 1; i <= n; ++i) answer(i, A[i]);
}
