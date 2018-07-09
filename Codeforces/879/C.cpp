#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int a = 0, b = 1023;
int mk[2][3][3][3][3][3];
int A[6];



int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	while(n--) {
		char c;
		int x;
		cin >> c >> x;
		if(c == '|') {
			a |= x;
			b |= x;
		}
		if(c == '^') {
			a ^= x;
			b ^= x;
		}
		if(c == '&') {
			a &= x;
			b &= x;
		}
	}
	recur(0, 0);
	recur(1, 0);
}