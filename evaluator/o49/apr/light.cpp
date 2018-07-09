#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>
#include <vector>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1<<17;

int l, n;
P t[MAXN<<1];
bool lz[MAXN<<1];
vector<int> V;

void build(int p = 1, int l = 0, int r = n) {
	if(l == r) {
		t[p] = {V[l+1] - V[l], 0};
		return;
	}
	build(p<<1, l, (l+r)/2);
	build(p<<1|1, (l+r)/2 + 1, r);
	t[p] = {t[p<<1].x + t[p<<1|1].x, t[p<<1].y + t[p<<1|1].y};
}

void update(int x, int p = 1, int l = 0, int r = n) {
	if(lz[p] != 0) {
		swap(t[p].x, t[p].y);
		if(l != r) {
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
		lz[p] = 0;
	}
	if(r < x) return;
	if(x <= l) {
		swap(t[p].x, t[p].y);
		if(l != r) {
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
		return;
	}
	update(x, p<<1, l, (l+r)/2);
	update(x, p<<1|1, (l+r)/2+1, r);
	t[p] = {t[p<<1].x + t[p<<1|1].x, t[p<<1].y + t[p<<1|1].y};
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> l >> n;
	V.reserve(n+5);
	queue<int> Q;
	V.emplace_back(0), V.emplace_back(l);
	for(int i = 0; i < n; ++i) {
		int x = input();
		V.emplace_back(x);
		Q.push(x);
	}
	sort(all(V));
	build();
	while(!Q.empty()) {
		int x = lower_bound(all(V), Q.front()) - V.begin();
		Q.pop();
		update(x);
		printf("%d\n", t[1]);
	}
}	