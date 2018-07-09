#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, t[N];

void upd(int x) {
	for(int i = x; i; i -= i & -i) t[i]++;
}

int que(int x) {
	int sum = 0;
	for(int i = x; i <= n; i += i & -i) sum += t[i];
	return sum;
}

int main() {
	scanf("%d", &n);
	long long inv = 0;
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		inv += que(now);
		upd(now);
	}
	bool st = inv & 1, st2 = n & 1;
	if(st == st2) puts("Petr"); //Um_nik
	else puts("Um_nik");
}