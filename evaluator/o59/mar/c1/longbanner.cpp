#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1e5 + 5;

int n, h, l, sz, X[MAXN], Y[MAXN], t[MAXN<<1];
vector<int> coor;
void upd(int x, int v) { for(t[x += sz] += v; x != 1; x >>= 1) t[x>>1] = t[x] + t[x^1]; }
int get(int l, int r) {
	int sum = 0;
	for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if(l&1) sum += t[l++];
		if(r&1) sum += t[--r];
	}
	return sum;
}
int idx(int x) { return lower_bound(all(coor), x) - coor.begin(); }
int iup(int x) { return upper_bound(all(coor), x) - coor.begin(); }

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &h, &l);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", X+i, Y+i);
		coor.emplace_back(Y[i]);
	}
	sort(all(coor)); coor.resize(unique(all(coor)) - coor.begin()); sz = coor.size();
	int pv = 1, mx = 0;
	for(int i = 1; i <= n; ++i) {
		upd(idx(Y[i]), 1);
		while(X[i] - X[pv] > h) upd(idx(Y[pv++]), -1);		
		for(int j = 0; j <= l; ++j) {
			int a = idx(Y[i]-l+j), b = iup(Y[i]+j);
			int ret = get(a, b);
			mx = max(mx, ret);
		}
	}
	printf("%d\n", mx);
}