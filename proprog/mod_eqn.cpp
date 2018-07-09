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

struct data {
	long x, y, d;
};

long a, b, c;

data extended(long a, long b) {
	
}

int main() {
	red();
	cin >> a >> b >> c;
	auto now = extended(a, c);
}