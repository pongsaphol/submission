#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n;
char A[N], B[N];

int main() {
	scanf("%d", &n);
	scanf("%s %s", A+1, B+1);
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		map<int, int> M;
		M[A[i]]--, M[B[i]]++, M[A[n-i+1]]--, M[B[n-i+1]]++;
		for(auto x : M) sum += x.second > 0;
	}
	printf("%d\n", sum >> 1);
}
