#include <cstdio>
#include <algorithm>

using namespace std;

char arr[1005][1005];
pair<int,int> z[] = {{-1,-1},{-2,-2},{1,1},{2,2},{1,-1},{2,-2},{-1,1},{-2,2}};
pair<int,int> p[] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
	//freopen("r","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt = 0;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			scanf(" %c",&arr[i][j]);
			if(arr[i][j] == 'A'){
				cnt++;
			}
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(arr[i][j] == 'x'){
				arr[i][j] = '.';
				for(int k = 0;k<8;++k){
					int x = z[k].first+i;
					int y = z[k].second+j;
					if(x<1||x>n||y<1||y>m)continue;
					if(arr[x][y] == 'A'){
						cnt--;
						arr[x][y] = '.';
					}
				}
			}else if(arr[i][j] == '+'){
				arr[i][j] = '.';
				for(int k = 0;k<4;++k){
					int x = p[k].first+i;
					int y = p[k].second+j;
					if(x<1||x>n||y<1||y>m)continue;
					if(arr[x][y] == 'A'){
						cnt--;
						arr[x][y] = '.';
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	for(int i = 1;i<=n;++i){
		printf("%s\n",arr[i]+1);
	}
}