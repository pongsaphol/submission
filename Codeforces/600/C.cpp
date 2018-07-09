#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 2e5 + 5;

char A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A);
	vector<int> V;
	int n = 0;
	for(; A[++n];) V.emplace_back(A[n]);
	sort(all(V));
	vector<int> ans;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(n - i <= cnt) break;
		if(V[i] == V[i+1]) ans.emplace_back(V[i++]);
		else ans.emplace_back(V[i]), cnt++;
	}
	for(auto x : ans) printf("%c", x);
	for(int i = ans.size() - 1 - (n%2); i >= 0; --i) printf("%c", ans[i]);	
}