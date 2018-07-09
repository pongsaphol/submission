#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e6+5;
char A[MAXN],a[MAXN];
char ans[MAXN];
int main(){
	//freopen("r","r",stdin);
	scanf("%s%s",A,a);
	int len = strlen(A);
	for(int i = 0;i<len;++i){
		int x = A[i],y = a[i];
		if(x>='a')x = x-'a'+'A';
		if(y>='a')y = y-'a'+'A';
		int en = x-y;
		if(en<0)en+=26;
		if(en>9){
			printf("R.I.P.\n");
			return 0;
		}
		ans[i] = en+'0';
	}
	printf("%s",ans);
}