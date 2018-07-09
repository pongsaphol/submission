#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1<<19;

int n, m, lz[MAXN<<1];

void upd(int x, int y, int v, int p = 1, int l = 1, int r = n) {
	if(x > y) return;
	if(lz[p] != 0) return;
	if(x > r || l > y) return;
	if(x <= l && r <= y) {
		lz[p] = v;
		return;
	}
	upd(x, y, v, p<<1, l, (l+r)/2);
	upd(x, y, v, p<<1|1, (l+r)/2+1, r);
}

int que(int x, int p = 1, int l = 1, int r = n) {
	if(l == r) return lz[p];
	if(lz[p] != 0) {
		if(lz[p<<1] == 0) lz[p<<1] = lz[p];
		if(lz[p<<1|1] == 0) lz[p<<1|1] = lz[p];
		lz[p] = 0;
	}
	if(x <= (l+r)/2) return que(x, p<<1, l, (l+r)/2);
	else return que(x, p<<1|1, (l+r)/2+1, r);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		upd(a, c-1, c);
		upd(c+1, b, c);
	}
	for(int i = 1; i <= n; ++i) {
		cout << que(i) << " ";
	}
}