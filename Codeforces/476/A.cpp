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

int main() {
	red();
	int a = input(), b = input();
	if(a < b) return !puts("-1")&0;
	int ret = (a+1)/2;
	while(ret % b != 0) ret++;
	return !printf("%d\n", ret);
}