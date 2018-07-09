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

const int MAXN = 1e3+10;

int A[MAXN], pv[MAXN];

int main() {
	red();
	memset(A, -1, sizeof A);
	A[1] = 0;
	for(int i = 1; i <= 1000; ++i) {
		if(A[i] == -1) continue;
		for(int j = 2; j <= 5; ++j) {
			int now = i+j;
			if(now % j == 0) continue;
			char B[6]; sprintf(B, "%d", now);
			bool st = false;
			for(int k = 0; B[k] != '\0'; ++k) if(B[k]-'0' == j) st = true;
			if(st) continue;
			// if(now == 51 && i == 46) dbg("bug");
			if(A[now] == -1) {
				A[now] = A[i]+1;
				pv[now] = i;
			} else if(A[now] > A[i] + 1) {
				A[now] = A[i] + 1;
				pv[now] = i;
			}
		}
	}
	int now = input();
	printf("%d\n", A[now]);
	// while(now != 1) {
	// 	printf("%d\n", pv[now]);
	// 	now = pv[now];
	// }
}