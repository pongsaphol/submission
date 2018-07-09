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

const int MAXN = 5e5+5;

int n, k, A[MAXN], cnt[MAXN<<1];

int main() {
	red();
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	int p = 1, cc = 0, x = 0, y = 0;
	for(int i = 1; i <= n; ++i) {
		while(p <= n) {
			if(++cnt[A[p]] == 1) cc++;
			if(cc > k) {
				if(--cnt[A[p]] == 0) cc--;
				break;
			}
			p++;
		}
		if(--cnt[A[i]] == 0) cc--;
		if(y - x < p - i) y = p, x = i;
	}
	printf("%d %d\n", x, y-1);
}