#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17, X = 1e6+5;

struct data {
	int l, r, d;
	data(int l, int r, int d) : l(l), r(r), d(d) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.r < b.r;
	}
};


int n, t, p, A[N], ans[N], freq[X];
vector<int> pwn[X];

int add(int a, int b) { return (a + b) % p; }
int sub(int a, int b) { return (a - b + p) % p; }
int mul(int a, int b) {return ((long)a * b) % p; }
int f(int x) {
	return mul(freq[A[x]], pwn[A[x]][freq[A[x]]]);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &t, &p);
	pwn[0].emplace_back(0);
	for(int i = 0; i < n; ++i) {
		scanf("%d", A+i);
		if(pwn[A[i]].empty()) pwn[A[i]].emplace_back(1);
		pwn[A[i]].emplace_back(mul(A[i], pwn[A[i]].back()));
	}
	int sz = sqrt(n) + 1;
	vector<data> block[sz];
	for(int i = 1; i <= t; ++i) {
		int a, b; scanf("%d %d", &a, &b); a--, b--;
		block[a/sz].emplace_back(a, b, i);
	}
	for(int i = 0; i < sz; ++i) {
		sort(block[i].begin(), block[i].end());
		block[i].emplace_back((i+1)*sz, (i+1)*sz-1, 0);
		int l = i*sz, r = i*sz, sum = 0;
		for(auto x : block[i]) {
			while(r <= x.r) {
				sum = sub(sum, f(r));
				freq[A[r]]++;
				sum = add(sum, f(r));
				r++;
			}
			while(l < x.l) {
				sum = sub(sum, f(l));
				freq[A[l]]--;
				sum = add(sum, f(l));
				l++;
			}
			while(l > x.l) {
				l--;
				sum = sub(sum, f(l));
				freq[A[l]]++;
				sum = add(sum, f(l));
			}
			ans[x.d] = sum;
		}
	}
	for(int i = 1; i <= t; ++i) printf("%d\n", ans[i]);
}