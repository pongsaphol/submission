#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
using namespace std;

int n;
vector<P> V;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		V.emplace_back(b, a);
	}
	sort(all(V));
	int last = 0, cnt = 0;
	for(auto x : V) {
		if(x.y > last) {
			last = x.x;
			cnt++;
		}
	}
	cout << cnt;
}