#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m, A[MAXN];
map<int, int> M;
set<int> S;

void add(int x) {
	if(M[x] == 0) S.emplace(x);
	if(M[x] == 1) S.erase(x);
	M[x]++;
}

void del(int x) {
	if(M[x] == 2) S.emplace(x);
	if(M[x] == 1) S.erase(x);
	M[x]--;
}

void print() {
	if(S.empty()) puts("Nothing");
	else printf("%d\n", *S.rbegin());
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	for(int i = 1; i <= m; ++i) add(A[i]);
	print();
	for(int i = m+1; i <= n; ++i) {
		add(A[i]), del(A[i-m]);
		print();
	}
}