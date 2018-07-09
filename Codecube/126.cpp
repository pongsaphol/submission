#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
	bool X[4][4];
}node;
node l[10];
char arr[5][30];

void build(){
	l[0].X[1][2] = true;
	l[0].X[2][1] = true;
	l[0].X[2][3] = true;
	l[0].X[3][1] = true;
	l[0].X[3][2] = true;
	l[0].X[3][3] = true;
	l[1].X[2][3] = true;
	l[1].X[3][3] = true;
	l[2].X[1][2] = true;
	l[2].X[2][2] = true;
	l[2].X[2][3] = true;
	l[2].X[3][1] = true;
	l[2].X[3][2] = true;
	l[3].X[1][2] = true;
	l[3].X[2][2] = true;
	l[3].X[2][3] = true;
	l[3].X[3][2] = true;
	l[3].X[3][3] = true;
	l[4].X[2][1] = true;
	l[4].X[2][2] = true;
	l[4].X[2][3] = true;
	l[4].X[3][3] = true;
	l[5].X[1][2] = true;
	l[5].X[2][1] = true;
	l[5].X[2][2] = true;
	l[5].X[3][2] = true;
	l[5].X[3][3] = true;
	l[6].X[1][2] = true;
	l[6].X[2][1] = true;
	l[6].X[2][2] = true;
	l[6].X[3][1] = true;
	l[6].X[3][2] = true;
	l[6].X[3][3] = true;
	l[7].X[1][2] = true;
	l[7].X[2][3] = true;
	l[7].X[3][3] = true;
	l[8].X[1][2] = true;
	l[8].X[2][1] = true;
	l[8].X[2][2] = true;
	l[8].X[2][3] = true;
	l[8].X[3][1] = true;
	l[8].X[3][2] = true;
	l[8].X[3][3] = true;
	l[9].X[1][2] = true;
	l[9].X[2][1] = true;
	l[9].X[2][2] = true;
	l[9].X[2][3] = true;
	l[9].X[3][2] = true;
	l[9].X[3][3] = true;
}
int A[] = {0,3,7,10};
int B[] = {2,9,5,9};
bool anc[4][10];
int solve(){
	//int ans = 1;
	for(int z = 0;z<4;++z){
		int cnt = 0;
		for(int i = 0;i<=B[z];++i){
			bool st = true;
			//printf("--------\n%d\n",i);
			for(int j = 1;j<=3;++j){
				for(int k = 1;k<=3;++k){
					if(arr[j][k+A[z]] != ' ' && l[i].X[j][k] == false){
						st = false;
					}
					//printf("%d",l[i].X[j][k]);
				}
				//printf("\n");
			}
			//printf("--->%d\n",st);
			if(st){
				anc[z][i] = true;
			}
		}
		//printf("->%d<-\n",cnt);
		//ans*=cnt;
		//printf("==========\n");
	}
	int ans = 0;
	int cache = 1;
	int in = 0;
	for(int i = 0;i<2;++i)in+=anc[0][i];cache*=in;in = 0;
	for(int i = 0;i<10;++i)in+=anc[1][i];cache*=in;in = 0;
	for(int i = 0;i<6;++i)in+=anc[2][i];cache*=in;in = 0;
	for(int i = 0;i<10;++i)in+=anc[3][i];cache*=in;in = 0;
	ans+=cache;cache = 1;
	if(anc[0][2] == true){
		//printf("do\n");
		for(int i = 0;i<4;++i)in+=anc[1][i];cache*=in;in = 0;
		for(int i = 0;i<6;++i)in+=anc[2][i];cache*=in;in = 0;
		for(int i = 0;i<10;++i)in+=anc[3][i];cache*=in;in = 0;
		ans+=cache;
	}	
	return ans;
}

int main(){
	//freopen("r","r",stdin);
	build();
	for(int i = 1;i<=3;++i)gets(arr[i]+1);
	for(int i = 1;i<=3;++i){
		for(int j = 1;j<=20;++j){
			if(arr[i][j] == '\0')arr[i][j] = ' ';
		}
	}
	printf("%d\n",solve());
}
/*
 _      _  _
| | _ . _||_
|_| _|. _|| 
*/