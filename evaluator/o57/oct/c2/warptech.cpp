#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

struct node{
	int a, b, c;
	friend inline bool operator<(const node &a, const node &b) {
		return a.c < b.c;
	}
};

int n, m, k, P[5005];

int find(int x) {
	if(P[x] == x) return x;
	return P[x] = find(P[x]);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	vector<node> V;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		V.push_back({a, b, c});
	}
	sort(all(V));
	while(k--) {
		for(int i = 0; i < n; ++i) P[i] = i;
		int mx = 0, f = input(), sum = n;
		for(auto x:V) {
			int a = find(x.a);
			int b = find(x.b);
			if(a != b) {
				P[a] = b;
				mx = x.c;
				sum--;
			}
			if(sum == f) break;
		}
		printf("%d\n", mx);
	}
}