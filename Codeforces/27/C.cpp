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

int A[MAXN], comp[MAXN], id[MAXN];

int main() {
	red();
	int n = input();
	if(n <= 2) return !printf("0");
	for(int i = 1; i <= n; ++i) A[i] = input();
	int cc = 0;
	for(int i = 1; i <= n; ++i) {
		if(A[i] != A[i-1]) {
			comp[++cc] = A[i];
			id[cc] = i;
		}
	}
	for(int i = 1; i <= cc-2; ++i) {
		if((comp[i+1] < comp[i] && comp[i+1] < comp[i+2]) || (comp[i+1] > comp[i] && comp[i+1] > comp[i+2])) {
			return !printf("3\n%d %d %d\n", id[i], id[i+1], id[i+2]);
		}
	}
	puts("0");
}