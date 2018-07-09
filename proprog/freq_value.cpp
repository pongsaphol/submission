#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1<<17;

int n, m, arr[MAXN], t[MAXN<<1], pre[MAXN];

int query(int l, int r) {
	int mx = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}
	return mx;
}

int main() {
	// freopen("r", "r", stdin);
	while(scanf("%d%d", &n, &m) , n) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", arr+i);
			if(arr[i] == arr[i-1]) t[i+n] = t[i+n-1]+1;
			else t[i+n] = 1;
		}
		// build tree
		for(int i = n; i >= 1; --i) t[i] = max(t[i<<1], t[i<<1|1]);
		int p = n+1;
		for(int i = n; i >= 1; --i) {
			if(t[i+n] == 1) pre[i] = p = i;
			else pre[i] = p;
		}
		while(m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int nl = pre[l];
			if(nl > r) printf("%d\n", r-l+1);
			else printf("%d\n", max(query(nl, r+1), nl - l));
		}
	}
}