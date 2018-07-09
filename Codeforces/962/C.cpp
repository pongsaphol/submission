#include <bits/stdc++.h>
using namespace std;

char A[20], ret[20];

int main() {
	int mn = 20;
	scanf("%s", A);
	int n = strlen(A);
	set<int> perf;
	for(int i = 1; i * i <= (int)2e9; ++i) perf.emplace(i*i);
	for(int i = 1; i < (1<<n); ++i) {
		int ptr = 0, cnt = 0;
		for(int j = 0; j < n; ++j) if(i & (1 << j)) {
			if(!ptr and A[j] == '0') break;
			ret[ptr++] = A[j];
			cnt++;
		}
		if(!ptr) continue; ret[ptr] = 0;
		int num; sscanf(ret, "%d", &num);
		if(perf.count(num)) mn = min(mn, n - cnt); 
	}
	printf("%d", mn == 20 ? -1 : mn);
}