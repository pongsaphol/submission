#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	if(n == m) return !printf("=");
	
	double lhs = m * log2(n);
	double rhs = n * log2(m);
	if(lhs == rhs) printf("=");
	else if(lhs > rhs) printf(">");
	else printf("<");
}