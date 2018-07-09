#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1<<18;

int n, m;
long t[MAXN<<1], lz[MAXN<<1];
vector<int> A;

struct data {
	int a, b, c, d;
};

void update(int x, int y, int v, int p = 1, int l = 0, int r = A.size() - 2) {
	if(lz[p] != 0) {
		t[p] += lz[p] * (A[r+1] - A[l]);
		if(l != r) {
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p] = 0;
	}
	if(r < x || y < l) return;
	if(x <= l && r <= y) {
		t[p] += (long)v * (A[r+1] - A[l]);
		if(l != r) {
			lz[p<<1] += v;
			lz[p<<1|1] += v;
		}
		return;
	}
	update(x, y, v, p<<1, l, (l+r)/2);
	update(x, y, v, p<<1|1, (l+r)/2 + 1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

long query(int x, int y, int p = 1, int l = 0, int r = A.size() - 2) {
	if(lz[p] != 0) {
		t[p] += lz[p] * (A[r+1] - A[l]);
		if(l != r) {
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p] = 0;
	}
	if(r < x || y < l) return 0;
	if(x <= l && r <= y) return t[p];
	return query(x, y, p<<1, l, (l+r)/2) + query(x, y, p<<1|1, (l+r)/2 + 1, r);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	set<int> S;
	vector<data> V;
	S.emplace(n), S.emplace(0);
	while(m--) {
		int a = input(), b = input(), c = input();
		S.emplace(b), S.emplace(c);
		if(a) V.push_back({a, b, c});
		else {
			int d = input();
			V.push_back({a, b, c, d});
		} 
	}
	for(auto x:S) A.emplace_back(x);
	for(auto &x:V) {
		x.b = lower_bound(all(A), x.b) - A.begin();
		x.c = lower_bound(all(A), x.c) - A.begin() - 1;
		if(x.a) printf("%lld\n", query(x.b, x.c));
		else update(x.b, x.c, x.d);
	}
}