#include <bits/stdc++.h>
using namespace std;


void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

char A[1005], B[1005];

int main() {
	ref();
	scanf("%s %s", A, B);
	int len = strlen(A);
	set<char> V[128];
	for(int i = 0; i < len; ++i) {
		if(A[i] > B[i]) swap(A[i], B[i]);
		if(A[i] == B[i]) continue;
		V[A[i]].emplace(B[i]);
		V[B[i]].emplace(A[i]);
		if(V[A[i]].size() > 1 || V[B[i]].size() > 1) return !printf("-1\n");
	}
	vector<pair<int, int> > ans;

	for(int i = 1; i < 128; ++i) {
		if(V[i].size() > 1) return !printf("-1\n");
		if(V[i].size() == 1) {
			ans.emplace_back(i, *V[i].begin());
			V[*V[i].begin()].erase(i);
		}
	}
	printf("%d\n", ans.size());
	for(auto x:ans) {
		printf("%c %c\n", x.first, x.second);
	}
}