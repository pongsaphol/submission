#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

int t[2][MAXN][MAXN];

void upd(int _x, int x, int y) {
	for(int i = x; i < MAXN; i += i&-i) {
		for(int j = y; j < MAXN; j += j&-j) {
			t[_x][i][j]++;
		}
	}
}

int que(int _x, int x, int y) {
	int sum = 0;
	for(int i = x; i != 0; i -= i&-i) {
		for(int j = y; j != 0; j -= j&-j) {
			sum += t[_x][i][j];
		}
	}
	return sum;
}

int n;
void find(int &x, int &y) {
	int sm = 7501 - x;
	int lev = (y+1)/2 + (5001-x)/2;
	x = sm - lev + 1, y = lev + 1;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	// for(int i = 5; i != 1; --i) {
	// 	for(int j = 1; j <= 6; ++j) {
	// 		int x = i, y = j;
	// 		find(x, y);
	// 		printf("(%d, %d)", x, y);
	// 	}
	// 	puts("");
	// }
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		swap(a, b);
		if(a%2 != b%2) {
			int x = a, y = b;
			find(x, y);
			printf("%d\n", que(0, x, y));
			upd(0, x, y);
			// printf("0 : %d %d\n", x, y);
			// x = a, y = b-1;
			// find(x, y);
			// printf("1 : %d %d\n", x, y);
			upd(1, x, y);
		} else {
			int x = a+1, y = b;
			find(x, y);
			
			printf("%d\n", que(1, x, y));
			upd(1, x, y);
			// printf("1 : %d %d\n", x, y);

			x = a-1, y = b;
			find(x, y);
			// printf("0 : %d %d\n", x, y);
			upd(0, x, y);
		}
	}
}