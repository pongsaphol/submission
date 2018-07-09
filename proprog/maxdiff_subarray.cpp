#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long arr[5][10005];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(arr,0,sizeof arr);
        int n;
        scanf("%d",&n);
        long long mxdiff = 0;
        for(int i = 1;i<=n;++i){
            scanf("%lld",&arr[0][i]);
        }
        arr[1][0] = -1e9;
        arr[2][n+1] = 1e9;
        for(int i = 1;i<=n;++i){
            arr[1][i] = max(arr[1][i-1],0ll)+arr[0][i];
        }
        for(int i = 1;i<=n;++i){
            arr[1][i] = max(arr[1][i],arr[1][i-1]);
        }
        for(int i = n;i>=1;--i){
            arr[2][i] = min(arr[2][i+1],0ll)+arr[0][i];
        }
        for(int i = n;i>=1;--i){
            arr[2][i] = min(arr[2][i],arr[2][i+1]);
        }
        for(int i = 1;i<n;++i){
            mxdiff = max(mxdiff,abs(arr[1][i]-arr[2][i+1]));
        }
        for(int i = 1;i*2<=n;++i){
            swap(arr[0][i],arr[0][n-i+1]);
        }
        for(int i = 1;i<=n;++i){
            arr[1][i] = max(arr[1][i-1],0ll)+arr[0][i];
        }
        for(int i = 1;i<=n;++i){
            arr[1][i] = max(arr[1][i],arr[1][i-1]);
        }
        for(int i = n;i>=1;--i){
            arr[2][i] = min(arr[2][i+1],0ll)+arr[0][i];
        }
        for(int i = n;i>=1;--i){
            arr[2][i] = min(arr[2][i],arr[2][i+1]);
        }
        for(int i = 1;i<n;++i){
            mxdiff = max(mxdiff,abs(arr[1][i]-arr[2][i+1]));
            //printf("->%d %d::%d\n",arr[1][i],arr[2][i+1],abs(arr[1][i]-arr[2][i+1]));
        }
        printf("%lld\n",mxdiff);
    }
}
