#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

int sum;

int main() {
	red();
	int n = input();
	int x = n;
	while(n--) sum += input();
	double ans = (double)sum/(double)(x);
	printf("%.6f", ans);
}