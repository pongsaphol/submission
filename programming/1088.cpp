#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int n, m;

int cnt[3];
int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	map<int,int> M;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		M[a]++;
		M[b+1]--;
	}
	int p = 1;
	int val = 0;
	M[n+1] = 0;
	for(auto x: M) {
		cnt[val] += x.first - p;
		val = (val+x.second+300000000)%3;
		// printf("%d:: %d %d\n", val, x.first, x.second);
		p = x.first;
	}
	char z;
	scanf(" %c", &z);
	int x;
	if(z == 'R') x = 0;
	if(z == 'G') x = 1;
	if(z == 'B') x = 2;
	int sum = 0;
	for(int i = 0; i < 3; ++i) {
		if(i == x) continue;
		if((x == 2 && i == 0 )||(x == 1 && i == 2)||(x == 0 && i == 1))sum += cnt[i] * 2;
		else sum += cnt[i] * 1;
	}
	printf("%d\n", sum);
}
