#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
using namespace std;

const int N = 1 << 17;

struct data {
	int x, y, z;
	data(int x, int y = 0, int z = 0) : x(x), y(y), z(z) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.x < b.x;
	}
};

int b, n, d, m;
vector<data> V;
long ans;

void solve1() {
	deque<int> Q;
	for(auto x : data) {
		while(!Q.empty() and Q.front() + d < x.x) Q.pop_front();
		ans += Q.size();
		Q.push_back(x.x);
	}
}

vector<int> t[N<<1][2], coord;



void solve2() {
	// I will use coord comporess
	for(auto x : V) coord.emplace_back(x);
	sort(all(coord));
	coord.resize(unique(all(coord)) - coord.begin());

}

int main() {
	scanf("%d %d %d %d", &b, &n, &d, &m);
	for(int i = 1; i <= n; ++i) {
		int x, y, z; 
		if(b >= 1) scanf("%d", &x);
		if(b >= 2) scanf("%d", &y);
		if(b >= 3) scanf("%d", &z);
		V.emplace_back(x, y, z);
	}
	sort(V.begin(), V.end());
	if(b == 1) solve1();
	if(b == 2) solve2();
	if(b == 3) solve3();
}