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

const int MAXN = 1e6 + 5;

char A[MAXN];
int m;
long suma, sumb;
int main() {
	red();
	scanf("%s", A);
	int len = strlen(A);
	for(m = 0; A[m] != '^'; ++m){}
	for(int i = 0; i < m; ++i) {
		if(A[i] >= '0' && A[i] <= '9') {
			// cout << i << endl;
			suma += (m-i)*(A[i]-'0');
		}
	}
	for(int i = m+1; i < len; ++i) {
		if(A[i] >= '0' && A[i] <= '9') {
			sumb += (i-m)*(A[i]-'0');
		}	
	}
	// cout << suma << endl << sumb << endl;
	puts((suma == sumb ? "balance":(suma > sumb?"left":"right")));
}