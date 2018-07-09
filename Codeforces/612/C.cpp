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

const int MAXN = 1e6+5;

int H[128];
char f[] = "<>{}[]()", A[MAXN];

int main() {
	red();
	for(int i = 0; i < 8; ++i) H[f[i]] = i;
	int cnt = 0;
	stack<char> S;
	scanf("%s", A);
	int n = strlen(A);
	for(int i = 0; i < n; ++i) {
		if(H[A[i]] % 2) {
			if(S.empty()) return puts("Impossible")&0;
			int a = (H[S.top()]/2), b = H[A[i]]/2;
			if(a != b) cnt++;
			S.pop();
		} else S.push(A[i]);
	}
	if(!S.empty()) return puts("Impossible")&0;
	return !printf("%d\n", cnt);
}