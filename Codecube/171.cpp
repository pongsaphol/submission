#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 4e5 + 5;

int n, m;
char A[MAXN];
vector<P> L[MAXN];
set<int> st[MAXN], ed[MAXN];
bool ans[MAXN];

int main() {
	// freopen("r", "r", stdin);
	stack<int> S;
	scanf("%s", A+1);
	n = strlen(A+1);
	scanf("%d", &m);
	for(int i = 1; i <= n; ++i) A[n+i] = A[i];
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b) b += n;
		L[b].emplace_back(a, i);
	}
	for(int i = 1; i <= n/2; ++i) S.push(-1);
	for(int i = 1, cc = 0; i <= 2*n; ++i) {
		if(A[i] == '(') S.push(i);
		else {
			st[S.size()].emplace(S.top());
			ed[S.size()].emplace(i);
			st[S.size()+1].clear(), ed[S.size()+1].clear();
			for(auto x : L[i]) if(st[S.size()].find(x.x) != st[S.size()].end()) ans[x.y] = true;
			S.pop();
		}
	}
	for(int i = 1; i <= m; ++i) puts(ans[i] ? "yes" : "no");
}