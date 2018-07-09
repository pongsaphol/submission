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
	vector<int> V;
	for(int i = 0; i < 4; ++i) V.emplace_back(input());
	sort(all(V));
	if(V[0] + V[1] > V[2] || V[1] + V[2] > V[3]) return puts("TRIANGLE")&0;
	if(V[0] + V[1] == V[2] || V[1] + V[2] == V[3]) return puts("SEGMENT")&0;
	return puts("IMPOSSIBLE")&0;
}