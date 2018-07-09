#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
char A[MAXN], ans[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	scanf("%s", A);
	set<int> S;
	for(int i = 0; i < n; ++i) S.emplace(A[i]);
	vector<int> V;
	map<int, int> M;
	int idx = 0;
	int sz = S.size();
	for(auto x : S) {
		M[x] = idx++;
		V.emplace_back(x);
	}
	if(n < m) {
		for(int i = n; i < m; ++i) {
			A[i] = V[0];
		}
		return !printf("%s", A);
	}
	for(int i = 0; i < m; ++i) {
		ans[i] = M[A[i]];
	}
	ans[m-1]++;
	for(int i = m-1; i >= 0; --i) {
		if(ans[i] == sz) {
			ans[i] = 0;
			ans[i-1]++;
		} else {
			break;
		}
	}
	for(int i = 0; i < m; ++i) printf("%c", V[ans[i]]);
}