#include <cstdio>
#include <cstring>
char arr[] = "codecube";

char now[100005];

int main(){
	//freopen("r","r",stdin);
	scanf("%s",now);
	int len = strlen(now);
	int idx = 0,cnt = 0;
	for(int i = 0;i<len;++i){
		while(1){
			if(arr[idx] == now[i]) break;
			idx++;
			idx%=8;
			cnt++;
		}
		idx++;
		idx%=8;
	}
	if(idx == 0)printf("%d\n",cnt);
	else printf("%d\n",cnt+8-idx);
}