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

const int MAXN = 2e5+5;

int n, A[MAXN], inf;
long sum, mx, s[MAXN];

struct CH {
	#define pl pair<long, long>
	vector<pl> S;
	bool cut(pl c) {
		pl a = S[S.size()-2], b = S[S.size()-1];
		return (c.y-a.y)*(a.x-b.x) < (b.y-a.y)*(a.x-c.x);
	}
	void add(long xx, long yy) {
		pl ret(xx, yy);
		while(S.size() >= 2 && cut(ret)) S.pop_back();
		S.emplace_back(ret);
	}
	long find(int ptr, long ret) {
		return S[ptr].x*ret + S[ptr].y;
	}
	long query(long ret) {
		int l = 0, r = S.size()-1;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(find(m-1, ret) > find(m, ret)) l = m;
			else r = m-1;
		}
		return find(l, ret);
	}
};

int main() {
	red();
	n = input();
	for(int i = 1; i <= n; ++i) {
		s[i] = A[i] = input();
		s[i] += s[i-1];
		sum += (long)i*A[i];
	}
	CH ch, ch2;
	ch.add(n, s[n]);
	for(int i = n-1; i != 0; --i) {
		ch.add(i+1, s[i+1]);
		mx = max(mx, s[i] - (long)i*A[i] - ch.query(-A[i]));
	}
	for(int i = 2; i <= n; ++i) {
		ch2.add(-i+1, s[i-2]);
		mx = max(mx, s[i-1] - (long)i*A[i] - ch2.query(A[i]));
	}
	cout << mx+sum << endl;
}