#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[105];

int main() {
	scanf("%s", arr);
	int len = strlen(arr);
	int cnt = 0;
	for(int i = 0; i < len; ++i) {
		if(arr[i] == 'd' && arr[i+1] == 'z' && arr[i+2] == '=') {
			cnt++;
			i+=2;
		}else if(arr[i] == 'c' && arr[i+1] == '=') {
			cnt++;
			i++;
		}else if(arr[i] == 'c' && arr[i+1] == '-') {
			cnt++;
			i++;
		}else if(arr[i] == 'd' && arr[i+1] == '-') {
			cnt++;
			i++;
		}else if(arr[i] == 'l' && arr[i+1] == 'j') {
			cnt++;
			i++;
		}else if(arr[i] == 'n' && arr[i+1] == 'j') {
			cnt++;
			i++;
		}else if(arr[i] == 's' && arr[i+1] == '=') {
			cnt++;
			i++;
		}else if(arr[i] == 'z' && arr[i+1] == '=') {
			cnt++;
			i++;
		}else cnt++;
	}
	printf("%d\n", cnt);
}