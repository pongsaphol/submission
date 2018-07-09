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

int x, y;

int main() {
	red();
	int n = input();
	bool st = false;
	while(n--) {
		int a = input(), b = input();
		x += a, y += b;
		if(a%2 == 0 && b%2 == 1) st = true;
		if(a%2 == 1 && b%2 == 0) st = true;
 	}
 	if(x % 2 == 0 && y % 2 == 0) return puts("0")&0;
 	if((x%2) && (y%2)) if(st) return puts("1")&0;
 	return puts("-1")&0;
}