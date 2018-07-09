#include <cstdio>
#include <algorithm>
using namespace std;

int arr[105];

int main() {
	freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", arr+i);
	}
	int gcd = abs(arr[1]-arr[2]);
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			gcd = __gcd(gcd, abs(arr[i]-arr[j]));
		}
	}
	printf("%d ", gcd);
	for(int i = 2; i*i <= gcd; ++i) {
		if(i*i == gcd) {
			printf("%d", i);
			break;
		}
		if(gcd%i == 0) {
			printf("%d %d ", i, gcd/i);
		}
	}
}