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

vector<int> g[1005];

int main() {
	red();
	int n = input();
	for(int i = 2; i <= n; ++i) {
		int x = input();
		g[x].emplace_back(i);
		g[i].emplace_back(x);
	}
	for(int i = 1; i <= n; ++i) {
		if(g[i].size() == 1) continue;
		int cnt = 0;
		for(auto v:g[i]) cnt += (g[v].size() == 1);
		if(cnt < 3) return !printf("No");
	}
	puts("Yes");
}