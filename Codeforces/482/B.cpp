#include <bits/stdc++.h>
using namespace std; 

#define iii tuple<int, int, int>

const int N = 1e5+5;

int n, m, pref[30][N], pos[30][N];

int main() {
	scanf("%d %d", &n, &m);
	vector<iii> V;
	for(int i = 0, l, r, v; i < m; ++i) {
		scanf("%d %d %d", &l, &r, &v);
		for(int j = 0; j < 30; ++j) 
			if(v >> j & 1) pref[j][l]++, pref[j][r+1]--;
			else V.emplace_back(l, r, j);
	}
	for(int i = 0; i < 30; ++i) for(int j = 1; j <= n; ++j) {
		pref[i][j] += pref[i][j-1];
		if(!pref[i][j]) pos[i][j]++;
	}
	for(int i = 0; i < 30; ++i) for(int j = 1; j <= n; ++j) 
		pos[i][j] += pos[i][j-1];
	for(auto x : V) {
		int l, r, v; tie(l, r, v) = x;
		if(!(pos[v][r] - pos[v][l-1])) return !printf("NO");
	}
	puts("YES");
	for(int i = 1; i <= n; ++i) {
		int val = 0;
		for(int j = 0; j < 30; ++j) if(pref[j][i]) val |= (1 << j);
		printf("%d ", val);
	}
}