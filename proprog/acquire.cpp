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

const int MAXN = 5e4+5;

int n;
vector<P> V, ret;
long dp[MAXN];
vector<pair<int, long> > S;

long cost(int p, int q) { return (long)S[p].x*q + S[p].y; }

bool f(pair<int, long> now) {
	int d1 = S.size() - 2, d2 = S.size() - 1;
	long x = (long)(S[d1].x-now.x)*(now.y-S[d2].y);
	long y = (long)(S[d2].x-now.x)*(now.y-S[d1].y);
	return x < y;
}
int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		V.emplace_back(a, b);
	}
	sort(all(V), greater<P>());
	ret.emplace_back(0, 0);
	int mn = 0;
	for(auto x:V) {
		if(x.y > mn) {
			mn = x.y;
			ret.emplace_back(x);
		}
	}
	// int sz = ret.size()-1, ptr = 0;
	// for(int i = 1; i <= sz; ++i) {
	// y = mx + c;
	// 	for(int j = 1; j <= i; ++j) dp[i] = min(dp[i], ret[j].x*ret[i].y + dp[j-1]);
	// }
	for(int i = 1; i <= sz; ++i) {
		while(S.size() >= 2 && f(make_pair(ret[i].x, dp[i-1]))) S.pop_back();
		S.emplace_back(ret[i].x, dp[i-1]);
		while(ptr < S.size()-1 && cost(ptr, ret[i].y) > cost(ptr+1, ret[i].y)) ptr++;
		if(ptr >= S.size()) ptr = S.size()-1;
		dp[i] = cost(ptr, ret[i].y);
	}
	printf("%lld\n", dp[sz]);
}