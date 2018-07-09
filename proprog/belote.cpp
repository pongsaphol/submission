#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[] = "AKQJT987";
int ds[] = {11, 4, 3, 20, 10, 14, 0, 0};
int rs[] = {11, 4, 3, 2, 10, 0, 0, 0};
int A[256][2];

void build() {
	for(int i = 0; i < 8; ++i) {
		A[arr[i]][1] = ds[i];
		A[arr[i]][0] = rs[i];
	}
}

int main() {
	// freopen("r", "r", stdin);
	build();
	int n;
	char x;
	scanf("%d %c", &n, &x);
	int sum = 0;
	for(int i = 0; i < 4*n; ++i) {
		char a, b;
		scanf(" %c %c", &a, &b);
		sum += A[a][b==x];
	}
	printf("%d\n", sum);
}