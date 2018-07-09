#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, A[100005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		A[i] += A[i-1];
	}
	for(int i = 1; i < n; ++i) {
		if(A[i] == A[n] - A[i]) return !printf("%d\n", i);
	}
	for(int i = 1; i < n; ++i) {
		//I will bsearch
		int L = i+1, R = n, c = A[n] - A[i];
		while(L < R) {
			int mid = (L+R+1)/2;
			if(A[n] - A[mid] + A[i] >= A[mid] - A[i]) L = mid;
			else R = mid-1;
		}
		if(A[n] - A[L] + A[i] == A[L] - A[i]) return !printf("%d %d\n", i, R);
	}
	return !printf("NO\n");
}