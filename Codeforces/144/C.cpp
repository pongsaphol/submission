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

int cc[26], _cc[26];
char A[MAXN], B[MAXN];

bool check() {
	for(int i = 0; i < 26; ++i) {
		if(cc[i] > _cc[i]) return false;
	}
	return true;
}

int main() {
	red();
	scanf("%s", A);
	scanf("%s", B);
	int sum = 0, n = strlen(A), m = strlen(B);
	if(n < m) return !printf("0\n");
	for(int i = 0; i < m; ++i) {
		if(A[i] != '?') cc[A[i]-'a']++;
		_cc[B[i]-'a']++;
	}	
	sum += check();
	for(int i = m; i < n; ++i) {
		if(A[i-m] != '?') cc[A[i-m]-'a']--;
		if(A[i] != '?') cc[A[i]-'a']++;
		sum += check();
	}
	printf("%d\n", sum);
}