#include <cstdio>
#include <iostream>
int a, a2 = 1023;
int n, x;
char c;
int main() {
	scanf("%d",&n);
	while(n--) {
		while(c=getchar(),c=='\n'||c==' ');
		scanf("%d",&x);	
		if(c=='&')a&=x,a2&=x;
		if(c=='|')a|=x,a2|=x;
		if(c=='^')a^=x,a2^=x;	
	}
	printf("2\n| %d\n^ %d\n",(a^(a2^1023)),(1023^a2));
	return 0;
}