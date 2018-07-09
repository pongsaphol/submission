#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

const int N = 1e5+5;

int n, m, A[N], t[N<<1];
vector<int> T[N<<1]; 

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A+i), t[i+n] = A[i], T[i+n].emplace_back(A[i]);
	for(int i = n-1; i; --i) {
		t[i] = __gcd(t[i<<1], t[i<<1|1]);
		for(auto x : T[i<<1]) T[i].emplace_back(x);
		for(auto x : T[i<<1|1]) T[i].emplace_back(x);
		sort(all(T[i]));
	}
	auto query = [&](int l, int r) {
		auto f = [&](int &a, int x) { if(a == -1) a = x; else a = __gcd(a, x); }; 
		int ret = -1;
		for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) f(ret, t[l++]);
			if(r & 1) f(ret, t[--r]); 
		}
		return ret;
	};
	scanf("%d", &m);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b); a--, b--;
		int l = a, r = b;
		int gcd = query(a, b);
		int sum = 0;
		auto f = [&](vector<int> &V) { return upper_bound(all(V), gcd) - lower_bound(all(V), gcd); };
		for(a += n, b += n+1; a < b; a >>= 1, b >>= 1) {
			if(a & 1) sum += f(T[a++]);
			if(b & 1) sum += f(T[--b]);
		}
		printf("%d\n", r-l+1-sum);
	}
}