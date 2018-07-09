#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

char A[MAXN];

int main() {
	// freopen("r", "r", stdin);
	scanf("%s", A);
	int n = strlen(A);
	int num = 0, cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(A[i] == '(') num++;
		else if(num) {
			num--;
			cnt += 2;
		}
	}
	cout << cnt;
}