#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, cc = 0;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= a; ++i) if(b % i == 0) if(b / i <= a) cc++;
	printf("%d\n", cc);
}