#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long llu;
int main(){
	//freopen("r","r",stdin);
	map<long long,bool> M;
	M[3ll] = true;
	M[7ll] = true;
	M[31ll] = true;
	M[127ll] = true;
	M[8191ll] = true;
	M[131071ll] = true;
	M[524287ll] = true;
	M[2147483647ll] = true;
	M[2305843009213693951ll] = true;
	int t;
	scanf("%d",&t);
	while(t--){
		long long now;
		scanf("%lld",&now);
		if(M[now])printf("YES\n");
		else printf("NO\n");
	}
}