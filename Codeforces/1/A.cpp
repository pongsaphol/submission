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
	int a, b, c;
	cin >> a >> b >> c;
	int x = a/c + (a%c?1:0);
	int y = b/c + (b%c?1:0);
	cout << (long)x*y << endl;
}