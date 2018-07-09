#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool st[25];
int n, m, arr[25][25];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", arr[i] + j);
		}
	}
	for(int i = 1; i <= m; ++i) {
		int a, b;
		a = b = 0;// a is 1, b is -1
		for(int j = 1; j <= n; ++j) {
			if(arr[j][i] == 1) a++;
			if(arr[j][i] == -1) b++;
		}
		int todel = 1e9;
		// printf("%d \n", todel);
		if(a > b) todel = -1;
		else if(a < b) todel = 1;
		// printf("%d\n", todel);
		for(int j = 1; j <= n; ++j) {
			if(arr[j][i] == todel) st[j] = true;
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i) sum += st[i];
	printf("%d\n", sum);
}