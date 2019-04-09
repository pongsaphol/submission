#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, sa[N], tmp[N], lcp[N], pos[N];
char inp[N];

int main() {
	scanf("%s", inp);
	n = strlen(inp);
	for(int i = 0; i < n; ++i) sa[i] = i, pos[i] = inp[i];
	for(int gap = 1; ; gap <<= 1) {
		auto cmp = [&](int a, int b) {
			if(pos[a] != pos[b]) return pos[a] < pos[b];
			a += gap, b += gap;
			return pos[a] == pos[b] ? a > b : pos[a] < pos[b];
		};
		sort(sa, sa+n, cmp);
		for(int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
		for(int i = 0; i < n; ++i) pos[sa[i]] = tmp[i];
		if(tmp[n-1] != n-1) break;
	}
	for(int i = 0, k = 0; i < n; ++i) if(pos[i] != n-1) {
		for(int j = sa[pos[i]+1]; inp[i+k] == inp[j+k]; ) ++k;
		lcp[pos[i]] = k;
		if(k) --k;
	} else k = 0;
}
