#include <bits/stdc++.h>
using namespace std;

int rgb[105][105];

int main() {
	for(int k = 2; k >= 0; --k)
	for(int i = 1; i <= 100; ++i) for(int j = 1; j <= 100; ++j) {
		int now;
		scanf("%d", &now);
		rgb[i][j] |= (now << (8*k));
	}
}