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

long dp[MAXN], inf = 1e18;
int pointer = 0;
vector<pair<long, long> > S; // m , c;

bool cut(pair<long, long> now) {
	int d1 = S.size() - 2, d2 = S.size() - 1;
	return (long)(S[d1].x-now.x)*(now.y-S[d2].y) < (long)(S[d2].x-now.x)*(now.y-S[d1].y);
}

bool f(long x) {
	return (long)S[pointer+1].x*x + S[pointer+1].y < (long)S[pointer].x*x + S[pointer].y;
}

int main() {
	red();
	int T = input();
	vector<P> V;
	while(T--) V.emplace_back(input(), input()*input());
	sort(all(V), greater<P>());
	vector<P> ret;
	ret.emplace_back(0, 0);
	int mx = 0, n = 0;
	for(auto x:V) {
		if(x.y > mx) {
			mx = x.y;
			ret.emplace_back(x);
			n++;
		}
	}
	// fill(dp+1, dp+MAXN, inf);
	// for(int i = 1; i <= n; ++i) {
	//  	for(int j = 1; j <= i; ++j) {
	//  		dp[i] = min(dp[i], dp[j-1] + (long)ret[j].x*ret[i].y);
	//  	}
	//  }
	for(int i = 1; i <= n; ++i) {
		while(S.size() >= 2 && cut(make_pair(ret[i].x, dp[i-1]))) S.pop_back();
		S.emplace_back(ret[i].x, dp[i-1]);
		if(pointer >= S.size()) pointer = S.size()-1;
		while(pointer < S.size()-1 && f(ret[i].y)) pointer++;
		dp[i] = (long)S[pointer].x*ret[i].y + S[pointer].y;
	}
	cout << dp[n] << endl;
}