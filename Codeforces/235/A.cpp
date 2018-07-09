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

long f(long a, long b, long c) {
	a = (a*b)/__gcd(a, b);
	return (a*c)/__gcd(a, c);
}

int main() {
	red();
	int n;
	scanf("%d", &n);
	vector<int> V;
	for(int i = n; i > max(0, n-200); --i) V.emplace_back(i);
	int m = V.size();
	long mx = n;
	for(int i = 0; i < m; ++i) for(int j = i+1; j < m; ++j)
	for(int k = j+1; k < m; ++k) { 
		mx = max(mx, f(V[i], V[j], V[k]));
	}
	cout << mx << endl;
}