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
}

const int MAXN = 3e5+5;

int n;
P A[MAXN];

int main() {
	red();
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		A[i] = {a, b};
	}
	sort(A, A+n, [&](P a, P b) { return a.y < b.y; });
	sort(A+1, A+n, [&](P a, P b) {
		return (long)(a.y-A[0].y)*(b.x-A[0].x) < (long)(b.y - A[0].y)*(a.x - A[0].x);
	});
	vector<P> S;
	S.emplace_back(A[0]), S.emplace_back(A[1]);
	int sz = S.size();
	for(int i = 2; i < n; ++i) {
		sz = S.size();
		while((long)(S[sz-1].y-S[sz-2].y)*(A[i].x-S[sz-2].x) > (long)(A[i].y-S[sz-2].y)*(S[sz-1].x-S[sz-2].x)) {
			S.pop_back();
			sz = S.size();
		}
		S.emplace_back(A[i]);
	}
	sz = S.size();
	long sum = 0;
	for(int i = 0; i < sz; ++i) {
		sum += ((long)S[i].x*S[(i+1)%sz].y) - ((long)S[i].x*S[(i-1+sz)%sz].y);
	}
	cout << (long)(sum/2) << '.' <<((abs(sum)%2)?"5":"0");
}