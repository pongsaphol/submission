#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

const int MAXN = 5e3+5;

int n, m, cnt[MAXN];
P A[MAXN];

P p1, p2, p3;

long sign(P x1, P x2, P x3) {
	return (long)(x1.x-x3.x)*(x2.y-x3.y)-(long)(x2.x-x3.x)*(x1.y-x3.y);
}

bool chk(P x1, P x2, P x3) {
	return (long)(x2.y-x1.y)*(x3.x-x1.x) == (long)(x3.y-x1.y)*(x2.x-x1.x);
}

bool cmp(int idx) {
	bool b1 = sign(A[idx], p1, p2) < 0ll;
	bool b2 = sign(A[idx], p2, p3) < 0ll;
	bool b3 = sign(A[idx], p3, p1) < 0ll;
	bool edge = chk(A[idx], p1, p2) || chk(A[idx], p2, p3) || chk(A[idx], p3, p1);
	return ((b1 == b2) && (b2 == b3))&!edge; 
}

int main() {
	red();
	n = input(), m = input();
	for(int i = 1; i <= n; ++i) {
		int a = input(), b = input();
		A[i] = {a, b};
	}
	while(m--) {
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		for(int i = 1; i <= n; ++i) cnt[i] += cmp(i);
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", cnt[i]);
}