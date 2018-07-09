#include <bits/stdc++.h>
using namespace std;


int main() {
	set<int> S;
	int n;
	scanf("%d", &n);
	while(n--) {
		int now;
		scanf("%d", &now);
		if(now) S.emplace(now);
	}
	cout << S.size();
}