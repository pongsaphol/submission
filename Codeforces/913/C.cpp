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

long A[35];

int main() {
	red();
	int n, k;
	cin >> n >> k;
	long sum = 0;
	A[0] = input();
	for(int i = 1; i < n; ++i) {
		A[i] = input();
		if((A[i-1]<<1) < A[i]) A[i] = (A[i-1]<<1); 
		if(k&(1<<i)) sum += A[i];
	}
	for(int i = n; i <= 30; ++i) A[i] = (A[i-1]<<1);
	long sumans = 0;
	for(int i = 30; i >= 0; --i) {
		if(k&(1<<i)) {
			sumans += A[i];
			sum -= A[i];
		} else {
			if(A[i] <= sum) {
				sumans += A[i];
				break;
			}
		}
	}
	cout << sumans;
}