#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	long a, b;
	cin >> a >> b;
	if(b-a <= 5) {
		long numb = 1;
		while(++a <= b) {
			numb *= a;
			numb %= 10;
		}
		cout << numb << endl;
	} else cout << "0" << endl;
}