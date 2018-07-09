#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1; i <= n; ++i)	{
		int now;
		scanf("%d", &now);
		sum += abs(now);
	}
	printf("%d\n", sum);
}