#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

char A[N];
int n, pos[N], sa[N], lcp[N], tmp[N];

int main() {
	scanf("%s", A);	
	n = strlen(A);
	for(int i = 0; i < n; ++i) pos[i] = A[i], sa[i] = i;
	for(int gap = 1; ; gap <<= 1) {
		auto cmp = [&](int a, int b) {
			if(pos[a] != pos[b]) return pos[a] < pos[b];
			a += gap, b += gap;
			return (a < n && b < n ? pos[a] < pos[b] : a > b);
		};
		sort(sa, sa+n, cmp);
		for(int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
		for(int i = 0; i < n; ++i) pos[sa[i]] = tmp[i];
		if(tmp[n-1] == n-1) break;
	}
	for(int i = 0, k = 0; i < n; ++i) if(pos[i] != n-1) {
		for(int j = sa[pos[i]+1]; max(i+k, j+k) < n && A[i+k] == A[j+k];) k++;
		lcp[pos[i]] = k;
		if(k) k--;
	} else k = 0;
}
