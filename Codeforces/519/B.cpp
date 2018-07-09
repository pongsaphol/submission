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
	multiset<int> A, B;
	int n = input();
	for(int i = 0; i < n; ++i) A.insert(input());
	for(int i = 1; i < n; ++i) {
		int now = input();
		A.erase(A.find(now));
		B.insert(now);
	}
	cout << *A.begin() << endl;
	for(int i = 2; i < n; ++i) B.erase(B.find(input()));
	cout << *B.begin() << endl;
}