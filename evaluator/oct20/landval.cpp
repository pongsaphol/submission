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

const int MAXN = 2e5+5;

int n, m, t[MAXN];

void update(int x, int v) {
	while(x <= n) {
		t[x] += v;
		x += x&-x;
	}
}

int query(int x) {
	int v = 0;
	while(x > 0) {
		v += t[x];
		x -= x&-x;
	}
	return v;
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	while(m--) {
		int met = input();
		if(met == 1) {
			int a, b, c;
			cin >> a >> b >> c;
			update(a, c);
			update(b+1, -c);
		} else {
			int a = input();
			printf("%d\n", query(a));
		}
	}
}