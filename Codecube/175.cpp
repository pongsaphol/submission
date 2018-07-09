#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int n, k, A[MAXN];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		char in[10]; scanf("%s", in);
		if(!strcmp(in, "UR")) A[i]++;
	}
	int sum = 0, mx = 0;
	for(int i = 0; i < k; ++i) sum += A[i];
	mx = max(mx, sum);
	for(int i = k; i < n; ++i) {
		sum += A[i] - A[i-k];
		mx = max(mx, sum);
	}
	printf("%d\n", mx);
}