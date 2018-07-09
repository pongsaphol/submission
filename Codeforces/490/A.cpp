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

vector<int> A[5];

int p1, p2, p3;

int main() {
	red();
	int n = input();
	for(int i = 1; i <= n; ++i) {
		A[input()].emplace_back(i);
	}
	for(int i = 1; i <= 3; ++i) sort(all(A[i]));
	int sz = min(A[1].size(), min(A[2].size(), A[3].size()));
	printf("%d\n", sz);
	for(int i = 0; i < sz; ++i) {
		printf("%d %d %d\n", A[1][i], A[2][i], A[3][i]);
	}	
}