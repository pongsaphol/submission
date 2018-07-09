#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1<<17;

int n, m, t[MAXN<<1];

void update(int idx, int val) {
	for(t[idx+=n] = val; idx > 1; idx>>=1) 
		t[idx>>1] = max(t[idx], t[idx^1]);
}

int query(int l, int r) {
	r++;
	int ans = -1e9;
	for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if(l&1) ans = max(ans, t[l++]);
		if(r&1) ans = max(ans, t[--r]);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		char x;
		int a, b;
		scanf(" %c %d %d", &x, &a, &b);
		if(x == 'U') update(a, b);
		else printf("%d\n", query(a, b));
	}
}