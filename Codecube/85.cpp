#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char arr[100005];
int chk[26];
int main(){
	//freopen("r","r",stdin);
	scanf("%s",arr+1);
	int len = strlen(arr+1);
	queue<int> Q;
	for(int i = 1;i*i<=len;++i){
		if(i*i==len){
			Q.push(i);
		}else if(len%i==0){
			Q.push(i);
			if(i!=1)Q.push(len/i);
		}
	}
	int mn = 1e9;
	while(!Q.empty()){
		int size = Q.front();
		Q.pop();
		int sum = 0;
		// printf("-----------\n");
		// printf("size = %d\n",size);
		for(int i = 1;i<=size;++i){
			memset(chk,0,sizeof chk);
			for(int j = 0;j<len/size;++j){
				chk[arr[j*size+i]-'a']++;
				//printf("%c",arr[j*size+i]);
			}
			//printf("\n");
			int inmx = 0;
			for(int j = 0;j<26;++j)inmx = max(inmx,chk[j]);
			sum+=len/size-inmx;
			//printf("%d\n",inmx);
		}
		mn = min(mn,sum);
	}
	printf("%d\n",mn);
}