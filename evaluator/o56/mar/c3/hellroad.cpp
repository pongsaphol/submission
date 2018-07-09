#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1005;

int n, k, H[MAXN];

struct data {
	int u, v, w;
	data(int u, int v, int w) : u(u), v(v), w(w) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.w < b.w;
	}
};

vector<data> V;

int find(int x) {
	if(!H[x]) return x;
	return H[x] = find(H[x]);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &k);
	for(int i = 0; i < (n*(n-1))/2; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V.emplace_back(a, b, c);
	}
	sort(all(V));
	int l = 1, r = 10000000;
	long sum = 0;
	while(l < r) {
		int m = (l+r+1) >> 1;
		sum = 0;
		int cnt = 0;
		memset(H, 0, sizeof H);
		for(auto x : V) {
			if(x.w < m) continue;
			int u = find(x.u), v = find(x.v);
			if(u != v) {
				H[u] = v;
				sum += x.w;
				cnt++;
			}
		}
		if(sum <= k && cnt == n-1) l = m;
		else r = m - 1;
	}
	printf("%d\n", l);
}