#include <bits/stdc++.h>
#define long long long
#define pll pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1e6+5;

int n;
long qs[N], dp[N], a, b, c;

struct CHT {
	int ptr = 0;
	vector<pll> S;
	bool cut(pll c) {
		auto a = S[S.size()-2], b = S[S.size()-1];
		return (c.y-a.y)*(a.x-b.x) < (b.y-a.y)*(a.x-c.x);
	}
	void add(long xx, long yy) {
		pll ret(xx, yy);
		while(S.size() >= 2 && cut(ret)) S.pop_back();
		S.push_back(ret);
	}
	long find(int idx, long v) { return S[idx].x * v + S[idx].y; }
	long query(long x) {
		while(ptr >= S.size()) ptr--;
		while(ptr < S.size() - 1 and find(ptr+1, x) < find(ptr, x)) ptr++;
		return find(ptr, x);
	}
};

long o(long x) { return x * x; }

void solve() {
	scanf("%d", &n);
	scanf("%lld %lld %lld", &a, &b, &c);
	CHT ch;
	ch.add(0, 0);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", qs+i), qs[i] += qs[i-1];
		dp[i] = a * o(qs[i]) + b * qs[i] + c - ch.query(qs[i]);
		ch.add(2 * a * qs[i], b * qs[i] - a * o(qs[i]) - dp[i]);
	}
	printf("%lld\n", dp[n]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
}