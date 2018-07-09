#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	//freopen("r", "r",stdin);
	int n;
	scanf("%d", &n);
	long long sum = 0;
	int cl = 0, cr = 0;
	while(n--){
		int k;
		scanf("%d", &k);
		sum += k;
		if(k%2 == 0) cl ++;
		else cr ++;
	}
	if(sum % 2 == 1) printf("First\n");
	else {
		if(cr % 2 == 0) printf("First\n");
		else printf("Second\n");
	}
}