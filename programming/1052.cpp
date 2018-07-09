#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN], B[MAXN], dpl[MAXN], dpr[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d %d", &A[i], &B[i]);
	int p = -1, a1, a2, mx1 = 0, mx2 = 0;
	for(int i = 1; i <= n; ++i) {
		if(p >= A[i]) dpr[i] = dpr[i-1] + 1;
		else dpr[i] = 1;
		p = max(p, A[i] + B[i] - 1);
		if(dpr[i] > mx1) mx1 = dpr[i], a1 = i - dpr[i] + 1;
	} p = 1e9 + 1;
	for(int i = n; i != 0; --i) {
		if(p <= A[i]) dpl[i] = dpl[i+1] + 1;
		else dpl[i] = 1;
		p = min(p, A[i] - B[i] + 1);
		if(dpl[i] >= mx2) mx2 = dpl[i], a2 = i + dpl[i] - 1;
	}
	if(mx1 > mx2) printf("%d R\n", a1);
	if(mx1 < mx2) printf("%d L\n", a2);
	if(mx1 == mx2) {
		if(a1 == a2) printf("%d L\n", a1);
		if(a1 > a2) printf("%d L\n", a2);
		if(a1 < a2) printf("%d R\n", a1);
	}
}