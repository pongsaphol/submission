#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char arr[100005];

int main(){
	//freopen("r","r",stdin);
	int T = 5;
	while(T--){
		scanf("%s",arr+1);
		int len = strlen(arr+1);
		queue<int> Q;
		for(int i = 1;i*i<=len;++i){
			if(i*i==len){
				Q.push(i);
				continue;
			}
			if(len%i==0){
				Q.push(i);
				Q.push(len/i);
			}
		}
		int track = len;
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			int lorb = len/now;
			bool st = true;
			//printf("->%d\n",now);
			for(int i = 1;i<=now;++i){
				char x = arr[i];
				for(int j = 1;j<lorb;++j){
					if(x != arr[j*now+i])st = false;
				}
				//printf("%d::%d\n",i,st?1:0);
			}
			//printf("%d\n",st);
			if(st)track = min(track,now);
			//printf("track = %d\n",track);
		}
		//printf("----->%d\n",track);
		int m = len/track;
		for(int i = 1;i*i<=m;++i){
			if(i*i == m){
				Q.push(i);
				continue;
			}
			if(m%i == 0){
				Q.push(i);
				Q.push(m/i);
			}
		}
		printf("%d\n",(int)Q.size());
	}	
}