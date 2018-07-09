#include <cstdio>
#include <set>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	set<int> S;
	while(n--) {
		int x;
		scanf("%d", &x);
		S.insert(x);
	}
	while(m--) {
		int x;
		scanf("%d", &x);
		if(S.find(x) == S.end()) puts("n");
		else puts("y");
	}
}