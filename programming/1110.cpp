#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int z = 1e6+1;
int V[1000005];
int m1[2000005];
int m2[2000005];
int main(){
	//freopen("1110-20.in","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	int st;
	for(int i = 0;i<n;++i){
		int now;
		scanf("%d",&now);
		if(now-k==0){ V[i]=0;st = i;}
		if(now-k>0) V[i] = 1;
		if(now-k<0) V[i] = -1;
	}
	m1[z] = 1;
	m2[z] = 1;
	int L = st-1,R = st+1;
	int s1 = 0,s2 = 0;
	while(1){
		if(L>=0){
			s1+=V[L];
			m1[s1+z]++;
		}
		if(R<n){
			s2+=V[R];
			m2[s2+z]++;
		}
		L--;R++;
		if(L<0&&R>=n)break;
	}
	long long sum = 0;
	for(int i = 0;i<=n;++i){
		sum+=(long long)m1[i+z]*m2[-i+z];
		if(i!=0)sum+=(long long)m2[i+z]*m1[-i+z];
	}
	printf("%lld",sum);
}
