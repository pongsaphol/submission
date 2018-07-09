#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char arr2[25];

int main() {
	bool st = true;
	for(int i = 1; i <= 5; ++i) {
		scanf("%s", arr2);
		int len = strlen(arr2);
		for(int j = 0; j < len-2; ++j) {
			if(arr2[j] == 'F' && arr2[j+1] == 'B' && arr2[j+2] == 'I') {
				printf("%d\n", i);
				st = false;
				break;
			}
		}
	}
	if(st) printf("HE GOT AWAY!\n");
}
