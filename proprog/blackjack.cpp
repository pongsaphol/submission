#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3e5+5;

int n, m, arr[105];

void read() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", arr+i);
}

int solve() {
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			for(int k = j+1; k <= n; ++k) {
				int sum = arr[i] + arr[j] + arr[k];
				if(sum > mx && sum <= m) mx = sum;
			}
		}
	}
	return mx;
}

int main() {
	// freopen("r", "r", stdin);
	read();
	printf("%d\n", solve());
}