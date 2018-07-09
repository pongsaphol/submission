#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define P pair<int,int> 
#define x first
#define y second
using namespace std;

int n,a,b,c;

int list[3];

int main(){
	//freopen("r","r",stdin);
	scanf("%d",&n);
	for(int i = 0;i<3;++i)scanf("%d",list+i);
	for(int i = 0;i<n;++i){
		int idx = i%3;
		int &now = list[idx];
		int c1 = -1,c2 = -1;
		for(int j = 0;j<3;++j){
			if(idx == j)continue;
			if(c1 == -1)c1 = list[j];
			else c2 = list[j];
		}
		if(c1 > c2) swap(c1,c2);
		if(c1 > now)now = 2*c1-now;
		else if(c2 > now) now = 2*c2-now; 
	}
	for(int i = 0;i<3;++i)printf("%d\n",list[i]);
}