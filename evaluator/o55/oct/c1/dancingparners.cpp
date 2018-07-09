#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5+5;

int n, h[MAXN], d[MAXN];
P dpl[MAXN], dpr[MAXN];
int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	queue<P> Q;
	n = input();
	for(int i = 0; i < n; ++i) {
		int a = input(), b = input();
		Q.push({a, b});
	}
	h[0] = -1e9;
	dpl[0] = {(int)-1e9, 0};
	dpr[n+1] = {(int)-1e9, 0};
	for(int i = 1; i <= n+1; ++i) {
		int a = input(), b = input();
		h[i] = a;
		d[i] = b;
		dpl[i] = max(dpl[i-1], {b + a, i});
		dpr[i] = {b - a, i};
	}
	for(int i = n; i >= 0; --i) {
		dpr[i] = max(dpr[i], dpr[i+1]);
	}
	while(!Q.empty()) {
		auto now = Q.front();
		Q.pop();
		int idx = lower_bound(h+1, h+1+n, now.x) - h;
		int lidx = dpl[idx-1].y, ridx = dpr[idx].y;
		int L = now.y + d[lidx] - abs(now.x - h[lidx]);
		int R = now.y + d[ridx] - abs(now.x - h[ridx]);
		printf("%d\n", max(L, R));
	}
}