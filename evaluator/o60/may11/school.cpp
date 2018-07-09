#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 70005;

ordered_set<pii> t[N<<1];
int n, q, sz;
vector<int> coor;
vector<pii> inA, inB;

int get(int x) { return lower_bound(all(coor), x) - coor.begin(); }
int get2(int x) { return upper_bound(all(coor), x) - coor.begin()-1; }
int query(int l, int r, int x, int y) {
	int sum = 0;
	auto f = [&](int idx) {
		sum += t[idx].order_of_key(pii(y+1, 0)) - t[idx].order_of_key(pii(x, 0));
	};
	for(l += sz, r += sz+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) f(l++);
		if(r & 1) f(--r);
	}
	return sum;
}

int cidx;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		inA.emplace_back(a, b);
		coor.emplace_back(a);
	}
	for(int i = 1; i <= q; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		inB.emplace_back(a, b);
	}
	sort(all(coor)); coor.resize(unique(all(coor)) - coor.begin());
	sz = coor.size();
	for(auto x : inA) t[get(x.x)+sz].insert(pii(x.y, ++cidx));
	for(int i = sz-1; i != 0; --i) {
		for(auto x : t[i << 1]) t[i].insert(x);
		for(auto x : t[i << 1 | 1]) t[i].insert(x);
	}
	for(auto now : inB) {
		int x = get(now.x), y = get2(now.y);
		int a[5];
		a[1] = query(x, y, now.y+1, 1000000000);
		a[2] = query(0, x-1, now.x, now.y);
		a[3] = query(x, y, now.x, now.y);
		a[4] = query(0, x-1, now.y+1, 1000000000);
		a[0] = a[1] + a[2] + a[3] + a[4];
		for(int i = 0; i < 5; ++i) printf("%d ", a[i]);
		puts("");
	}
}