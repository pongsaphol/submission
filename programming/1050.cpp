#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 1e5;

string arr[MAXN+5], k;
map<string, int> M;
int n, m;

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int x;
			scanf("%d", &x);
			arr[i].push_back(x);
		}
	}
	for(int i = 1; i <= m; ++i) {
		int now;
		scanf("%d", &now);
		k.push_back(now);
	}
	for(int i = 1; i <= n; ++i) {
		if(arr[i] == k) {
			printf("%d\n", i);
			return 0;
		}
	}
	for(int i = 1; i <= n; ++i) {
		string V;
		for(int j = 0; j < m; ++j) {
			V.push_back(k[j] - arr[i][j]);
		}
		map<string, int>::iterator it;
		it = M.find(V);
		if(it != M.end()) {
			printf("%d %d\n", it->second, i);
			return 0;
		}
		M[arr[i]] = i;
		arr[i].clear();
	}
	printf("NO\n");
	return 0;
}