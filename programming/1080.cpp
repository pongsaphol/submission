#include <cstdio>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	// int arr[20];
	// if(n <= 3) {
	// 	while(1) printf("Helo wo");
	// }
	if(n < 3) {
		printf("%d\n", n);
		return 0;
	}
	vector<int> V;
	V.reserve(n);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		V.push_back(now);
	}
	sort(all(V));
	int mx = 0;
	for(int i = 0; i < n - 2; ++i) {
		int a = V[i], b = V[i+1];
		int x = a + b;
		int L = i + 2, R = n - 1;
		while(L < R) {
			int mid = (L+R+1)/2;
			if(V[mid] >= x) R = mid - 1;
			else L = mid;
		}
		if(V[L] < x)mx = max(mx, L - i + 1);
	}
	printf("%d\n", mx);
}