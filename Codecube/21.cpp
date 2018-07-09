#include <cstdio>
#include <algorithm>
#include <vector>
#define all(x) x.begin(),x.end()
using namespace std;
const int MAX = 20000;
vector<int> V[MAX<<2];
int n,m,st,ed,x,y,arr[MAX+5];
void build(int L = 1,int R = MAX,int ptr = 1){
	if(L==R){
		V[ptr].push_back(arr[L]);
		return;
	}
	for(int i = L;i<=R;++i){
		V[ptr].push_back(arr[i]);
	}
	sort(all(V[ptr]));
	int mid = (L+R)/2;
	build(L,mid,2*ptr);
	build(mid+1,R,2*ptr+1);
}
int query(int L = 1,int R = MAX,int ptr = 1){
	if(st>R||L>ed)return 0;
	if(st<=L&&R<=ed)return upper_bound(all(V[ptr]),y)-lower_bound(all(V[ptr]),x);
	int mid = (L+R)/2;
	return query(L,mid,2*ptr)+query(mid+1,R,2*ptr+1);
}
void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		scanf("%d",arr+i);
	}
	build();
}
int solve(){
	scanf("%d%d%d%d",&st,&ed,&x,&y);
	return query();
}
int main(){
	//freopen("_.in","r",stdin);
	read_input();
	while(m--)printf("%d ",solve());
	return 0;
}