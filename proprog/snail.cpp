#include <cstdio>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int L = 1, R = 1e9;
	while(L < R) {
		int mid = (L+R)/2;
		long long now = (long long)a*mid + (long long)b*(mid-1);
		if(now >= c) R = mid;
		L = mid+1;
	}
	printf("%d\n", R);
}