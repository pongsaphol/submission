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

map<string, int> M;

int main() {
	red();
	int T = input();
	while(T--) {
		string now;
		cin >> now;
		int cnt = M[now];
		if(cnt == 0) cout << "OK" << endl;
		else cout << now << cnt << endl;
		M[now]++;
	}
}