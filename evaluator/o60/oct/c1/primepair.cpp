#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e6;

int sieve[MAXN+5];

int mx, a1, a2, memo[MAXN];

int main() {
	// freopen("r", "r", stdin);
	for(int i = 2; i <= MAXN; ++i) {
		if(sieve[i]) continue;
		memo[i] = 1;
		for(int j = i+i; j <= MAXN; j += i) sieve[j] = i;
	}
	for(int i = 4; i <= MAXN; ++i) {
		if(memo[i] == 1) continue;
		memo[i] = memo[i/sieve[i]] + 1;
	}
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = 2; i <= MAXN; ++i) {
		int f = b/i, g = d/i;
		f*=i, g *=i;
		if(f < a || g < c) continue;
		if(memo[i] > mx) mx = memo[i], a1 = f, a2 = g;
		else if(memo[i] == mx) {
			if(a1 + a2 < f+g) a1 = f, a2 = g;
			else if(a1 + a2 == f + g) {
				if(a1 < f) a1 = f, a2 = g;
			}
		}
	}
	printf("%d %d\n", a1, a2);
}