#include <bits/stdc++.h>
using namespace std;

int n, X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
char A[100005], mem[128], xx[] = "UDRL";
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	for(int i = 0; i < 4; ++i) {
		mem[xx[i]] = i;
	}
	scanf("%d", &n);
	scanf("%s", A);
	int x = X[mem[A[0]]], y = Y[mem[A[0]]]; // up is true;
	bool site = y > x;
	int cnt = 0;
	for(int i = 1; i < n; ++i) {
		x += X[mem[A[i]]], y += Y[mem[A[i]]];
		if(x == y) continue;
		bool thiss = y > x;
		if(thiss == site) continue;
		site = thiss;
		cnt++; 
	}
	printf("%d\n", cnt);
}