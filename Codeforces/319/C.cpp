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

const int MAXN = 1e5+5;

int n;
long dp[MAXN];
vector<P> ret(MAXN);

struct CH {
	#define pl pair<long, long>
	vector<pl> S;
	bool cut(const pl &c) {
		auto a = S[S.size()-2], b = S[S.size()-1];
		return (c.y-a.y)*(a.x-b.x) < (b.y-a.y)*(a.x-c.x);
	}
	void add(long xx, long yy) {
		pl ret(xx, yy);
		while(S.size() >= 2 && cut(ret)) S.pop_back();
		S.emplace_back(ret);
	}
	long find(int idx, long ret) {
		return S[idx].x*ret + S[idx].y;
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
	for(int i = 1; i <= n; ++i) ret[i].x = input();
	for(int i = 1; i <= n; ++i) ret[i].y = input();
	CH ch;
	for(int i = 2; i <= n; ++i) {
		ch.add(ret[i-1].y, dp[i-1]);
		dp[i] = ch.query(ret[i].x);
	}
	printf("%lld\n", dp[n]);
}