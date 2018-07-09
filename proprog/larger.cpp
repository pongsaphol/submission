#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char arr[10];

int main() {
	int n;
	scanf("%d", &n);
	sprintf(arr, "%d", n);
	int len = strlen(arr);
	sort(arr, arr+len);
	int mx = 1e9;
	do {
		int x;
		sscanf(arr, "%d", &x);
		if(x < mx && x > n) mx = x;
	} while(next_permutation(arr, arr+len));
	if(mx == 1e9) printf("0");
	else printf("%d", mx);
}