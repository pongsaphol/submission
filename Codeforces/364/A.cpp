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

char A[5005];
int a, qs[5005], num[100000];

int f(int x) {
	if(x > 50000) return 50000;
	return x;
}

int main() {
	red();
	scanf("%d", &a);
	scanf("%s", A+1);
	int n = strlen(A+1);
	for(int i = 1; i <= n; ++i) qs[i] = qs[i-1] + A[i] - '0';
	for(int i = 0; i < n; ++i) for(int j = i+1; j <= n; ++j) num[qs[j] - qs[i]]++;
	long ans = 0;
	if(a == 0) {
		long sum = 0;
		for(int i = 0; i <= 36000; ++i) sum += num[i];
		ans += sum*num[0];
	}
	for(int i = 1; i <= 36000; ++i) if(a%i == 0) ans += (long)num[i]*num[f(a/i)];
	cout << ans << endl;
}