#include <bits/stdc++.h>
#define long long long
using namespace std;

long k;
int n, m;

int main() {
	cin >> n >> m >> k;
	m--;
	if(k <= n-1) return !printf("%lld 1\n", k+1);
	k -= n;
	long row = k / m;
	long col = k % m;
	if(row % 2) col = m - col + 1;
	else col += 2;
	cout << n - row << " " << col << endl;
}