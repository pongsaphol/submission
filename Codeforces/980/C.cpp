#include <bits/stdc++.h>
using namespace std;

int n, k, idxg[300], A[100005], have[300];


int main() {
	memset(idxg, -1, sizeof idxg);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		have[A[i]] = true;
	}
	for(int i = 1; i <= n; ++i) {
		int mnp = max(A[i]-k+1, 0);
		if(idxg[A[i]] != -1) {
			printf("%d ", idxg[A[i]]);
			continue;
		}
		int last = A[i], ll = -1;
		for(int j = A[i]; j >= mnp; --j) {
			if(idxg[j] == -1) last = j;
			else {
				if(A[i] - idxg[j] + 1 <= k) ll = idxg[j];
				break;
			}
		}
		if(ll == -1) ll = last;
		// printf("->%d\n", last);
		for(int j = last; j <= A[i]; ++j) {
			idxg[j] = ll;
		}
		printf("%d ", idxg[A[i]]);
	}
}