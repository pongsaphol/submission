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

map<string, string> E;
set<string> nb;

int main() {
	red();
	int n = input();
	vector<pair<string, string> > ans;
	while(n--) {
		string a, b;
		cin >> a >> b;
		E[a] = b;
		nb.emplace(b);
	}
	for(auto x:E) {
		if(nb.count(x.x)) continue;
		auto ret = x.x;
		while(E.count(ret)) ret = E[ret];
		ans.emplace_back(x.x, ret);
	}
	cout << ans.size() << endl;
	for(auto x:ans) cout << x.x << " " << x.y << endl;
}