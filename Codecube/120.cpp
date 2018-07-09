#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e6+5;

int n, m, k, arr[15], dp[MAXN], p[MAXN];

void read_input() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", arr + i);
	}
}

typedef struct node {
	int num,idx,cnt;
}node;

bool cmp1(const node &a,const node &b) {
	return a.num > b.num;
}
bool cmp2(const node &a,const node &b) {
	return a.idx < b.idx;
}
void solve() {
	fill(dp, dp + MAXN, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= k; ++i) {
		int now = arr[i];
		for(int j = 0; j <= MAXN- 5 - now; ++j) {
			if(dp[j + now] > dp[j] + 1) {
				dp[j + now] = dp[j] + 1;
				p[j + now] = j;
			}
		}
	}
	int mn = 1e9,a1,a2;
	for(int i = n; i <= m; ++i) {
		if(dp[i] + dp[i-n] < mn) {
			mn = dp[i] + dp[i-n];
			a1 = i;
			a2 = i-n;
		}
	}
	printf("%d %d\n", dp[a1], dp[a2]);
	map<int, int> m1, m2;
	while(a1 > 0) {
		m1[a1 - p[a1]]++;
		a1 = p[a1];
	}
	while(a2 > 0) {
		m2[a2 - p[a2]]++;
		a2 = p[a2];
	}
	for(int i = 1; i <= k; ++i){
		printf("%d ", m1[arr[i]]);
	}
	printf("\n");
	for(int i = 1; i <= k; ++i){
		printf("%d ", m2[arr[i]]);
	}
	printf("\n");
}

int main() {
	//freopen("r","r",stdin);
	read_input();
	solve();
}