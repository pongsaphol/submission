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

int f[100];

bool chk[1005];

int main() {
	red();
	f[0] = 0, f[1] = 1;
	for(int i = 2; i < 100; ++i) {
		f[i] = f[i-1] + f[i-2];
		if(f[i] > 1000) break;
		chk[f[i]] = true;
	}
	int n = input();
	for(int i = 1; i <= n; ++i) {
		printf("%c", (chk[i]?'O':'o'));
	}
}