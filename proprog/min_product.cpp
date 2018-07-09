#include <cstdio>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
int arr[100005],pre[100005];
double L[100005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    deque<int> Q;
    for(int i = 1;i<=n;++i){
        scanf("%d",arr+i);
        L[i] = log2(arr[i]);
        if(!Q.empty()){
            L[i]+=L[Q.front()];
            pre[i] = Q.front();
        }
        if(!Q.empty()&&Q.front()==i-m)Q.pop_front();
        while(!Q.empty()&&L[Q.back()]>L[i])Q.pop_back();
        Q.push_back(i);
    }
    const long long MOD = 1e9+7;
    long long ans = 1;
    int st = n;
    while(st!=0){
        ans*=arr[st];
        ans%=MOD;
        st = pre[st];
    }
    printf("%lld\n",ans);
}
