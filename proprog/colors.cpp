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

int n, m, k, A[105][105];

void solve() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) A[i][j] = (input()?((i+j)%k+1):0);
	for(int i = 1; i <= n; ++i) {
		set<int> S;
		for(int j = 1; j <= m; ++j) {
			if(!A[i][j]) S.clear();
			else if(S.find(A[i][j]) == S.end()) S.emplace(A[i][j]);
			else {
				puts("NO");
				return;
			}
 		}
	}
	for(int i = 1; i <= m; ++i) {
		set<int> S;
		for(int j = 1; j <= n; ++j) {
			if(!A[j][i]) S.clear();
			else if(S.find(A[j][i]) == S.end()) S.emplace(A[j][i]);
			else {
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) printf("%d ", A[i][j]);
		printf("\n");
	}
	return;
}

int main() {
	red();
	int T = input();
	while(T--) solve();
}