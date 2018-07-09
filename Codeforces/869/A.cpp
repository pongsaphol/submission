#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <set>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 2001;

int n, A[MAXN], B[MAXN], cnt;
set<int> S;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 1; i <= n; ++i) A[i] = input();
	for(int i = 1; i <= n; ++i) B[i] = input();
	for(int i = 1; i <= n; ++i) S.emplace(A[i]), S.emplace(B[i]);
	for(int i = 1; i <= n; ++i) {
	for(int j = 1; j <= n; ++j) {
		int now = A[i] ^ B[j];
		if(S.find(now) != S.end()) cnt++;
	}}
	if(cnt%2) cout << "Koyomi" << endl;
	else cout << "Karen" << endl;
}