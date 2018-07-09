#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e6+5;

int n, dpl[MAXN], dpr[MAXN], A[MAXN], t[MAXN];

void upd(int x, int v) {
	while(x >= 1) {
		t[x] += v;
		x -= x&-x;
	}
}

int que(int x) {
	int v = 0;
	while(x <= n) {
		v += t[x];
		x += x&-x;
	}
	return v;
}

int main() {
	cin.sync_with_stdio(false);
	map<int, int> M;
	n = input();
	for(int i = 1; i <= n; ++i) {
		A[i] = input();
		M[A[i]]++;
		dpl[i] = M[A[i]];
		upd(dpl[i], 1);
	}
	M.clear();
	long sum = 0;
	for(int i = n; i >= 1; --i) {
		M[A[i]]++;
		dpr[i] = M[A[i]];
                upd(dpl[i], -1);
		sum += que(dpr[i]+1);
	}
	cout << sum << endl;
        return 0;
}