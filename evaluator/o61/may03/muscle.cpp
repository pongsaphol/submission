#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;

int n, t[N+1], A[N], ans[N];

void update(int x) {
	for(int i = x; i <= N; i += i&-i) t[i]--;
}

int query(int x) {
	int l = 1, ret = 0, r = N;
	while(l < r) {
		int m = (l + r) >> 1;
		if(t[m] + ret >= x) r = m;
		else l = m+1, ret += t[m];
	}
	return r;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= N; ++i) t[i] = i&-i;
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = n; i; --i) {
		ans[i] = query(i - A[i]);
		update(ans[i]);
	}
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}