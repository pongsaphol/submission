#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17;

int n, A[N];
list<int> Q[N];
pii t[N<<1];
long ans;

void update(int x, int y, int v, int p = 1, int l = 1, int r = n) {
	if(x <= l && r <= y) {
		t[p].x += v;
		if(t[p].x) t[p].y = r-l+1;
		else t[p].y = t[p<<1].y + t[p<<1|1].y;
		return;
	}
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	update(x, y, v, p<<1, l, m), update(x, y, v, p<<1|1, m+1, r);
	if(t[p].x) t[p].y = r-l+1;
	else t[p].y = t[p<<1].y + t[p<<1|1].y;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n-1; ++i) Q[i].push_back(0);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		if(Q[A[i]].size() == 6) {
			int ret = Q[A[i]].front(); Q[A[i]].pop_front();
			update(ret+1, Q[A[i]].front(), -1);
		}
		Q[A[i]].push_back(i);
		if(Q[A[i]].size() == 6) {
			auto it = Q[A[i]].begin();
			int a1 = *it; int a2 = *(++it);
			update(a1+1, a2, 1);		
		}
		ans += t[1].y;
	}
	printf("%lld\n", ans);
}
