#include <bits/stdc++.h>
using namespace std;


char S[1005];
int a[1005];
int main() {
	scanf("%s", S+1);
	int n = strlen(S+1);
	for(int i = 1; i <= n; ++i) if(S[i] != '.')a[i-1] |= 1<<(S[i] - 'A'), a[i] |= 1<<(S[i] - 'A'), a[i+1] |= 1<<(S[i] - 'A');
	for(int i = 1; i <= n; ++i) if(a[i] == 7) return !printf("Yes");
	puts("No");
}