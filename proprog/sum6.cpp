#include <cstdio>
#include <cstring>
using namespace std;

char A1[10], A2[10];

int main() {
	scanf("%s %s", A1, A2);
	int l1 = strlen(A1);
	int l2 = strlen(A2);
	for(int i = 0; i < l1; ++i) if(A1[i] == '6') A1[i] = '5';
	for(int i = 0; i < l2; ++i) if(A2[i] == '6') A2[i] = '5';
	int x, y;
	sscanf(A1, "%d", &x);
	sscanf(A2, "%d", &y);
	printf("%d ", x+y);
	for(int i = 0; i < l1; ++i) if(A1[i] == '5') A1[i] = '6';
	for(int i = 0; i < l2; ++i) if(A2[i] == '5') A2[i] = '6';
	sscanf(A1, "%d", &x);
	sscanf(A2, "%d", &y);
	printf("%d\n", x+y);
}