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

vector<int> V[10] = {{}, {}, {2}, {3}, {2, 2, 3}, {5}, {3, 5}, {7}, {2, 2, 2, 7}, {3, 3, 2, 7}};

int main() {
	red();
	int len = input();
	string inp;
	cin >> inp;
	vector<int> ans;
	for(int i = 0; i <len; ++i) {
		for(auto x:V[inp[i]-'0']) ans.emplace_back(x);
	}
	sort(all(ans), greater<int>());
	for(auto x:ans) printf("%d", x);
}