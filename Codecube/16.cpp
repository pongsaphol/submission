#include <cstdio>
#include <algorithm>
#include <deque>
#define long long long
using namespace std;

deque<int> Q;
int n;

void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=2*n;++i){
		int now;
		scanf("%d",&now);
		Q.push_back(now);
	}	

}

long solve(){
	sort(Q.begin(),Q.end());
	long sum = 0;
	for(int i = 1;i<=n;++i){
		sum+=(long)Q.front()*Q.back();
		Q.pop_front();Q.pop_back();
	}
	return sum;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}