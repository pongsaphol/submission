#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

int main() {
	red();
	int n = input();
	vector<int> V;
	bool st = false;
	for(int i = 0; i <= n; ++i) {
		V.emplace_back(input());
		if(i != 0 && V[i-1] != 1 && V[i] != 1) st = true;
	}
	if(!st) return puts("perfect")&0;
	puts("ambiguous");
	vector<int> ans;
	ans.emplace_back(0);
	printf("0 ");
	int touse = 0;
	int par = 1;
	for(int i = 1; i <= n; ++i) {
		if(V[i] != 1 && V[i+1] != 1 && touse == 0) {
			touse = 1;
			while(V[i]--) {
				printf("%d ", par);
				ans.emplace_back(par);
			}
			par = ans.size();
			continue;
		}
		if(touse == 1) {
			touse = -1;
			while(V[i]--) {
				printf("%d ", par);
				if(V[i] != 0)ans.emplace_back(par);
				else ans.emplace_back(par-1);
			}
			par = ans.size();
			continue;
		}
		while(V[i]--) {
			printf("%d ", par);
			ans.emplace_back(par);
		}
		par = ans.size();
	}
	printf("\n");
	for(auto x:ans) printf("%d ", x);
}