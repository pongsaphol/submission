#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1<<17, inf = 1e9;

int n, m;
P t[MAXN<<1];

void build() {
	for(int i = n-1; i > 0; --i) {
		t[i].x = min(t[i<<1].x, t[i<<1|1].x);
		t[i].y = max(t[i<<1].y, t[i<<1|1].y);
	}
}

void update(int x) {
	for(x += n; x > 1; x >>= 1) {
		t[x>>1].x = min(t[x].x, t[x^1].x);
		t[x>>1].y = max(t[x].y, t[x^1].y);
	}
}

P query(int l, int r) {
	P ret = {inf, -inf};
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) {
			ret.x = min(ret.x, t[l].x);
			ret.y = max(ret.y, t[l].y);
			l++;
		}
		if(r&1) {
			r--;
			ret.x = min(ret.x, t[r].x);
			ret.y = max(ret.y, t[r].y);
		}
	}
	return ret;
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) t[i+n] = {i, i};
	build();
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			auto now = query(b, c);
			if(now.x == b && now.y == c) printf("YES\n");
			else printf("NO\n");
		} else {
			swap(t[b+n], t[c+n]);
			update(b), update(c);
		}
	}
}