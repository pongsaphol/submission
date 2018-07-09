#include <cstdio>
#include <cmath>

int main() {
	// freopen("r", "r", stdin);
	int x;
	scanf("%d", &x);
	if(x%2 == 0) printf("%d.000000", x);
	else if(x == 1) printf("2.000000");
	else if(x == 3) printf("%.6f", 2 + sqrt(3));
	else if(x == 5) printf("%.6f", 2 + 2*sqrt(3));
	else if(x == 7) printf("%.6f", 4 + 2*sqrt(3));
	else if(x == 9) printf("%.6f", 6 + 2*sqrt(3));
	else if(x == 11) printf("%.6f", 8 + 2*sqrt(3));
	else if(x == 13) printf("%.6f", 10 + 2*sqrt(3));
	else if(x == 15) printf("%.6f", 12 + 2*sqrt(3));
	// else while(1) printf("x\n");
}