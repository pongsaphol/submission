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

const int MAXN = 1e5+5;

int n, m, t1[MAXN], t2[MAXN], t3[MAXN];

void update(int t[], int x, int v) {
	while(x <= n) {
		t[x] += v;
		x += x&-x;
	}
}

int query(int t[], int x) {
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
	n = input(), m = input();
	while(m--) {
		int met = input(), a = input(), b = input();
		if(met == 1) {
			if(query(t1, a) == query(t1, a-1)) update(t2, a, 1);
			if(query(t1, b+1) == query(t1, b)) update(t3, b+1, 1);
			update(t1, a, 1);
			update(t1, b+1, -1);
			if(query(t1, a) == query(t1, a-1)) update(t3, a, -1);
			if(query(t1, b) == query(t1, b+1)) update(t2, b+1, -1);
		} else if(met == 2) {
			printf("%d %d\n", query(t1, a), query(t1, b));
		} else {
			printf("%d %d %d %d\n", 
				query(t1, a), query(t1, b),
				query(t2, b) - query(t2, a),
				query(t3, b) - query(t3, a));
		}
	}
}