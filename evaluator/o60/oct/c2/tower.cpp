#include <iostream>
#include <algorithm>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1<<18;

int n, m, lz[MAXN<<1];
P t[MAXN<<1], E[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	t[p].y = 1;
	if(l == r) return;
	int mid = (l+r)/2;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
}

void update(int x, int y, int v, int p = 1, int l = 1, int r = n) {
	if(lz[p] != 0) {
		t[p].x += lz[p];
		E[p].x += lz[p];
		E[p].y += lz[p];
		if(l != r) {
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p] = 0;
	}
	if(y < l || r < x) return;
	if(x <= l && r <= y) {
		t[p].x += v;
		E[p].x += v;
		E[p].y += v;
		if(l != r) {
			lz[p<<1] += v;
			lz[p<<1|1] += v;
		}
		return;
	}
	int mid = (l+r)/2;
	update(x, y, v, p<<1, l, mid);
	update(x, y, v, p<<1|1, mid+1, r);
	E[p].x = E[p<<1].x;
	E[p].y = E[p<<1|1].y;
	if(t[p<<1].x != t[p<<1|1].x) {
		t[p] = max(t[p<<1], t[p<<1|1]);
		return;
	}
	int a = E[p<<1].y, b = E[p<<1|1].x;
	if(a == t[p<<1].x && b == t[p<<1].x) t[p] = {t[p<<1].x, t[p<<1].y + t[p<<1|1].y - 1};
	else t[p] = {t[p<<1].x, t[p<<1].y + t[p<<1|1].y};
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	build();
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		update(a, b, c);
		cout << t[1].x << " " << t[1].y << endl;
	}
}