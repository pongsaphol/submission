#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	m -= n-1;
	for(int i = 0; i < n; ++i) {
		int now;
		scanf("%d", &now);
		m -= now;
	}
	puts(m?"NO":"YES");
}