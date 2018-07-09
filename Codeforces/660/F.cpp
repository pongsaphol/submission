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

int n;
long s1[MAXN], s2[MAXN];

struct CH {
	vector<pair<long, long> > S;
	bool cut(pair<long, long> c) {
		auto a = S[S.size()-2], b = S[S.size()-1];
		return (c.y-a.y)*(a.x-b.x) < (b.y-a.y)*(a.x-c.x);
	}
	void add(long xx, long yy) {
		pair<long, long> ret(xx, yy);
		while(S.size() >= 3 && cut(ret)) S.pop_back();
		S.push_back(ret);
	}
	long find(int idx, long val) {
		return S[idx].x*val + S[idx].y;
	}
	long query(long val) {
		int L = 1, R = S.size()-1;
		while(L < R) {
			int m = (L + R + 1) >> 1;
			if(find(m-1, val) > find(m, val)) L = m;
			else R = m-1;
		}
		return find(L, val);
	}
	void print() {
		for(auto v:S) {
			cerr << "->" << v.x << endl;
		}
	}
};

int main() {
	red();
	n = input();
	CH ch;
	for(int i = 1; i <= n; ++i) {
		s1[i] = s2[i] = input();
		s1[i] = s1[i] + s1[i-1], s2[i] = s2[i]*i + s2[i-1];
	}
	long mx = 0;
	ch.add(1, 0);
	for(int i = 1; i <= n; ++i) {
		ch.add(1-i, s2[i-1] + s1[i-1]*(1-i));
		mx = max(mx, s2[i] - ch.query(-s1[i]));
	}
	ch.print();
	cout << mx << endl;
}