#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

int main() {
	ref();
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int x = a+b, y = c+d-min(c, d);
	puts((x <= y)?"Polycarp":"Vasiliy");
}