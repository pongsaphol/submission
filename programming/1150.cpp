#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[2][60005];
int mod = 60001;
int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	chk[0][30000] = true;
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		for(int j = mod-1; j >= 0; --j)
			chk[i&1][(j+mod+now)%mod] |= chk[(i-1)&1][j] | chk[(i-1)&1][(j+mod+now)%mod];
	}

	for(int j = mod-1; j >= 0; --j)
		if(chk[0][j] | chk[1][j]) {
			printf("%d\n", j-30000);
			return 0;
		}
}