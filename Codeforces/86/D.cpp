#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 2e5 + 5, MAXA = 1e6 + 5;

int n, t, freq[MAXA], A[MAXN];

struct data {
	int x, y, idx;
	data(int a, int b, int c) {x = a, y = b, idx = c; }
};

long sum = 0, ans[MAXN];
vector<data> V;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	for(int i = 1; i <= t; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		V.emplace_back(a, b, i);
	}
	int block = sqrt(n);
	sort(all(V), [&](const data &a, const data &b) {
		if(a.x/block != b.x/block) return a.x/block < b.x/block;
		return a.y < b.y;
	});
	int L = 1, R = 1;
	for(auto x : V) {
		int l = x.x, r = x.y;
		while(L < l) {
			sum -= (long)freq[A[L]]*freq[A[L]]*A[L];
			freq[A[L]]--;
			sum += (long)freq[A[L]]*freq[A[L]]*A[L];
			L++;
		}
		while(L > l) {
			L--;
			sum -= (long)freq[A[L]]*freq[A[L]]*A[L];
			freq[A[L]]++;
			sum += (long)freq[A[L]]*freq[A[L]]*A[L];
		}
		while(R <= r) {
			sum -= (long)freq[A[R]]*freq[A[R]]*A[R];
			freq[A[R]]++;
			sum += (long)freq[A[R]]*freq[A[R]]*A[R];
			R++;
		}
		while(R > r+1) {
			R--;
			sum -= (long)freq[A[R]]*freq[A[R]]*A[R];
			freq[A[R]]--;
			sum += (long)freq[A[R]]*freq[A[R]]*A[R];
		}
		ans[x.idx] = sum;
	}
	for(int i = 1; i <= t; ++i) printf("%lld\n", ans[i]);
}