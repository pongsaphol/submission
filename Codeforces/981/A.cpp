#include <bits/stdc++.h>
using namespace std;

const int N = 100;

char A[N];

bool chk(int a, int b) {
	for(int i = a, j = b; i <= b; ++i, --j) {
		if(A[i] != A[j]) return false;
	}
	return true;
}

int main() {
	scanf("%s", A);
	int n = strlen(A), mx = 0;
	for(int i = 0; i < n; ++i) for(int j = i; j < n; ++j) {
		if(!chk(i, j)) mx = max(mx, j - i + 1);
	}
	cout << mx;
}