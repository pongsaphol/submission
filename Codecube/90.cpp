#include <cstdio>
#include <algorithm>
using namespace std;

char arr[85][85];

int main(){
	//freopen("r","r",stdin);
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i = 1;i<=n;++i){
		scanf("%s",arr[i]+1);
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(arr[i][j] == 'B')arr[i][j] = '*';
			else if(arr[i][j] == 'V'){
				int now = i;
				while(++now<=n){
					if(arr[now][j] == '.') arr[now][j] = '|';
					else if(arr[now][j] == '-') arr[now][j] = '+';
					else if(arr[now][j] == 'B'){
						arr[now][j] = '*';
						break;
					}
					else break;
				}
			}else if(arr[i][j] == '^'){
				int now = i;
				//printf("%d %d\n",i,j);
				while(--now>=1){
					if(arr[now][j] == '.') arr[now][j] = '|';
					else if(arr[now][j] == '-') arr[now][j] = '+';
					else if(arr[now][j] == 'B'){
						arr[now][j] = '*';
						break;
					}
					else break;
				}
			}else if(arr[i][j] == '>'){
				int now = j;
				while(++now<=m){
					if(arr[i][now] == '.') arr[i][now] = '-';
					else if(arr[i][now] == '|') arr[i][now] = '+';
					else if(arr[i][now] == 'B'){
						arr[i][now] = '*';
						break;
					} 
					else break;
				}
			}else if(arr[i][j] == '<'){
				int now = j;
				while(--now>=1){
					if(arr[i][now] == '.') arr[i][now] = '-';
					else if(arr[i][now] == '|') arr[i][now] = '+';
					else if(arr[i][now] == 'B'){
						arr[i][now] = '*';
						break;
					}
					else break;
				}
			}
		}
	}
	for(int i = 1;i<=n;++i){
		printf("%s\n",arr[i]+1);
	}
}