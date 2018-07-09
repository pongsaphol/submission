#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e5;

int dp[MAXN+5][10];

char arr[MAXN+5], t[] = "codecube";

int main() {
	// freopen("r", "r", stdin);
	scanf("%s", arr);
	int len = strlen(arr);
	for(int z = 0; z < 8; ++z){ 
		int prev = 1e9;
		for(int i = len-1; i >= 0; --i) {
			if(arr[i] == t[z]) prev = i;
			dp[i][z] = prev;
		}
	}
	// for(int i = 0; i < 8; ++i) {
	// 	for(int j = 0; j < len; ++j) {
	// 		printf("%d ", dp[j][i]);
	// 	}
	// 	printf("\n");
	// }
	int mxl = 1e9;
	int a1 = -1e9, a2 = 1e9;
	for(int i = 0; i < len; ++i) {
		if(arr[i] == 'c') {
			int ed = i;
			for(int j = 1; j < 8; ++j) {
				ed = dp[ed][j];
				if(ed == 1e9) break;
			}
			if(ed-i < mxl) {
				mxl = ed-i;
				a1 = i;
				a2 = ed;
			}
		}
	}
	if(a2 == 1e9) printf("-1");
	else printf("%d %d\n", a1+1, a2+1);
}