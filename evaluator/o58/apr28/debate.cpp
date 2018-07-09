#include <bits/stdc++.h>
#define long long long
#define pil pair<int, long>
#define x first
#define y second
using namespace std;

long INF = 1e18;
const int N = 1<<17;

int n, q, e, A[N];
vector<pil> t[N<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p].emplace_back(A[l], A[r]);
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
	int p1 = 0, p2 = 0;
	while(p1 < t[p<<1].size() and p2 < t[p<<1|1].size()) {
		if(t[p<<1][p1].x < t[p<<1|1][p2].x) t[p].emplace_back(t[p<<1][p1].x, t[p<<1][p1].x), p1++;
		else t[p].emplace_back(t[p<<1|1][p2].x, t[p<<1|1][p2].x), p2++;
	}
	while(p1 < t[p<<1].size()) t[p].emplace_back(t[p<<1][p1].x, t[p<<1][p1].x), p1++;
	while(p2 < t[p<<1|1].size()) t[p].emplace_back(t[p<<1|1][p2].x, t[p<<1|1][p2].x), p2++;
	for(int i = 1; i < t[p].size(); ++i) t[p][i].y += t[p][i-1].y;
}

void query(int x, int y, vector<int> &v, int p = 1, int l = 1, int r = n) {
	if(x <= l and r <= y) {
		v.emplace_back(p);
		return;
	}
	if(x > r or l > y) return;
	int m = (l + r) >> 1;
	query(x, y, v, p << 1, l, m), query(x, y, v, p << 1 | 1, m + 1, r);
}

int main() {
	scanf("%d %d %d", &n, &q, &e);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();
	long pre = 0;
	while(q--) {
		int a, b; scanf("%d %d", &a, &b);
		if(e) a ^= pre, b ^= pre;
		vector<int> ret;
		query(a, b, ret);
		int l = 1, r = n;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			int sum = 0;
			for(auto x : ret) sum += upper_bound(t[x].begin(), t[x].end(), pil(m, INF)) - t[x].begin();
			if(sum <= ((b-a+1)>>1)) l = m;
			else r = m-1;
		}
		long sum = 0;
		for(auto x : ret) {
			auto it = upper_bound(t[x].begin(), t[x].end(), pil(l, INF));
			sum += t[x].rbegin()->y;
			if(it != t[x].begin()) {
				it--;
				sum -= 2ll * it->y;
			}
		}
		pre = sum;
		printf("%lld\n", sum); 
	}
}