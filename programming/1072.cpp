#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int n, m, A[N], start = 0;
bool chk;

int get(int idx) {
	if(chk) idx = start - idx;
	else idx = start + idx;
	return (idx + n) % n;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	while(m--) {
		char met; int a, b; 
		scanf(" %c %d", &met, &a);
		if(met == 'a') {
			scanf("%d", &b);
			swap(A[get(--a)], A[get(--b)]);
		} if(met == 'b') {
			scanf("%d", &b);
			A[get(--a)] = b;
		} if(met == 'c') {
			start = get(--a);
			chk ^= 1;
		} if(met == 'q') {
			printf("%d\n", A[get(--a)]);
		}
	}
}