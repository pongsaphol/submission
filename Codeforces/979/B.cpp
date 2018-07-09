#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, step[3][128], mx[3];
char A[3][N];

int main() {
	scanf("%d", &n);
	scanf("%s %s %s", A[0], A[1], A[2]);
	int len;
	for(int i = 0; i < 3; ++i) for(int j = 0; A[0][j]; len = ++j) step[i][A[i][j]]++;
	int z = 0;
	for(int i = 0; i < 3; ++i) {
		mx[i] = *max_element(step[i], step[i] + 128);
		if(mx[i] + n <= len) mx[i] += n;
		else if(mx[i] != len) mx[i] = len;
		else mx[i] -= n & 1;
	}
	if(mx[0] == mx[1] and mx[1] == mx[2]) return 0&puts("Draw");
	if(mx[0] > mx[1] and mx[0] > mx[2]) puts("Kuro");
	else if(mx[1] > mx[0] and mx[1] > mx[2]) puts("Shiro");
	else puts("Katie");
}