#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[20];
int len;
void m1() {
	printf(".");
	for(int i = 1; i <= len; ++i) {
		printf(".");
		if(i%3) printf("#");
		else printf("*");
		printf("..");
	}
	printf("\n");
}

void m2() {
	printf(".");
	for(int i = 1; i <= len; ++i) {
		if(i%3) printf("#");
		else printf("*");
		printf(".");
		if(i%3) printf("#");
		else printf("*");
		printf(".");
	}
	printf("\n");
}

void m3() {
	for(int i = 1; i <= len; ++i) {
		if(i == 1) printf("#");
		else{
			if(i%3 == 2) printf("#");
			else printf("*");
		}
		printf(".%c.", arr[i]);
	}
	if(len%3) printf("#");
	else printf("*");
	printf("\n");
}
int main() {
	// freopen("r", "r", stdin);
	scanf("%s", arr+1);
	len = strlen(arr+1);
	m1();
	m2();
	m3();
	m2();
	m1();
}