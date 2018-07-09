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

long sum;

int main() {
	red();
	int n = input();
	if(n < 10) sum = n;
	else if(n < 100) sum = 9 + 2*(n - 9);
	else if(n < 1000) sum = 9 + 2*90 + 3*(n - 99); 
	else if(n < 10000) sum = 9 + 2*90 + 3*900 + 4*(n - 999);
	else if(n < 100000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*(n - 9999);
	else if(n < 1000000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*(n - 99999);
	else if(n < 10000000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*(n - 999999);
	else if(n < 100000000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*9000000 + 8*(n - 9999999);
	else if(n < 1000000000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*9000000 + 8*90000000 + (long)9*(n - 99999999);
	else if(n == 1000000000) sum = 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*9000000 + 8*90000000 + (long)9*(900000000) + 10;
	cout << sum;
}