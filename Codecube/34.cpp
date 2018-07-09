#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int A[] = {5,9,5,9,9,9};
bool C[10];

int cnt(int idx){
	int sum = 0;
	for(int i = idx;i>=0;--i){
		if(!C[i])sum++;
	}
	return sum;
}

void solve(){
	memset(C,0,sizeof C);
	int n;scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		int now;scanf("%d",&now);
		C[now] = true;
	}
	char str[15];scanf("%s",str);
	vector<int> V;
	V.push_back(str[0]-'0');V.push_back(str[1]-'0');
	V.push_back(str[3]-'0');V.push_back(str[4]-'0');
	V.push_back(str[6]-'0');V.push_back(str[7]-'0');
	int sum = 0;
	for(int i = 0;i<6;++i){
		int now = cnt(V[i])-1;
		for(int j = i+1;j<6;++j)now*=cnt(A[j]);
		sum+=now;
		//printf("%d\n",sum);
	}
	printf("%02d:",sum/6000);sum%=6000;
	printf("%02d:",sum/100);sum%=100;
	printf("%02d\n",sum);
}

int main(){
	//freopen("r","r",stdin);
	int T;scanf("%d",&T);
	while(T--) solve();
}