#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;

int n, m, k, A[N], L[N], R[N];

bool chk(int z) {
	long sum = 0;
	for(int i = 1, pos = 0, cnt = 0; i <= n; ++i) {
		if(A[i] > z) {
			if(i != 1) L[++pos] = i-1;
			while(pos < k) L[++pos] = -n;
			break;
		}
		if(sum + A[i] > z || cnt == m) {
			L[++pos] = i-1;
			cnt = 1;
			sum = A[i];
		} else sum += A[i], cnt++;
		if(i == n) {
			L[++pos] = n;
			while(pos < k) L[++pos] = -n;
		}
	} sum = 0;
	for(int i = n, pos = 0, cnt = 0; i != 0; --i) {
		if(A[i] > z) {
			if(i != n) R[++pos] = i+1;
			while(pos < k) R[++pos] = n;
			break;
		}
		if(sum + A[i] > z || cnt == m) {
			R[++pos] = i+1;
			cnt = 1;
			sum = A[i];
		} else sum += A[i], cnt++;
		if(i == 1) {
			R[++pos] = n;
			while(pos < k) R[++pos] = n+1;
		}
	}
	for(int i = 0; i < k; ++i) if(R[i] - L[k-i-1] - 1 <= m) return true;
	return false;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	L[0] = 0, R[0] = n+1;
	int mx = 1e9;
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	int l = 0, r = 1e9;
	while(l < r) {
		int m = (l + r) >> 1;
		if(chk(m)) r = m;
		else l = m+1;
	}
	printf("%d\n", r);
}