#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

char arr[15];

int main() {
	// freopen("r", "r", stdin);
	stack<char> S;
	scanf("%s", arr);
	int len = strlen(arr);
	int z;
	scanf("%d", &z);
	int idx = len-z;
	while(z--) S.push('0');
	bool tod = false;
	if(arr[idx--] > '4') tod = true;
	while(idx >= 0) {
		if(tod) {
			arr[idx] ++;
			tod = false;
			if(arr[idx] <= '9') {
				S.push(arr[idx]);
			}else {
				tod = true;
				S.push('0');
			}
			idx--;
		}else {
			S.push(arr[idx--]);
		}
		// printf("%d\n", idx);
	}
	bool haveoutput = false;
	if(tod) {
		printf("1");
		haveoutput = true;
	}
	while(!S.empty()) {
		if(!haveoutput && S.top() == '0') {
			S.pop();
			continue;
		}
		printf("%c", S.top());
		haveoutput = true;
		S.pop();
	}
	if(!haveoutput) printf("0");
}