/*
TASK: o59_oct_c1_staying
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, A[3], dp[5][1005][8], mod = 1e9 + 7;
bool g[3][3] = {{0, 1, 1}, {0, 0, 1}, {1, 0, 0}};

int mic(int idx, int day, int bit) {
	int &sum = dp[idx][day][bit];
	if(sum != -1) return sum;
	sum = 0;
	for(int i = 1; i <= A[idx]; ++i) {
		if(day - i == 0) {
			if((bit|(1<<idx)) == 7) sum++;
			break;
		}
		for(int j = 0; j < 3; ++j) {
			if(g[idx][j]) {
				sum += mic(j, day - i, bit|(1<<idx));
				sum %= mod;
			}
		}
	}
	return sum;
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < 3; ++i) scanf("%d", A + i);
	printf("%d", mic(0, n, 0));
}
