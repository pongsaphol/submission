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


int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	int day = 0;
	for(int i = 1; i <= n; ++i) {
		int a = input(), b = input();
		if(day < a) day = a;
		else {
			while(day >= a) a += b;
			day = a;
		}
	}
	printf("%d\n", day);
}