#include <bits/stdc++.h>
using namespace std;

const int N = 1e2;

int n, A[N], s1, s2;

int main() {
	scanf("%d", &n);
	n >>= 1;
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	sort(A, A + n);
	for(int i = 0; i < n; ++i) s1 += abs(A[i] - 2*i - 1), s2 += abs(A[i] - 2*i - 2);
	cout << min(s1, s2);
}