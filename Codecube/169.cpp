#include <cstdio>
#include <algorithm>
using namespace std;
 
int s[100005];
 
int A[1000005],B[1000005];
int main(){
    for(int i = 1;i<=100000;++i){
        for(int j = i;j<=100000;j+=i){
            s[j]++;
        }
    }
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i){
        int now;scanf("%d",&now);
        A[i] = s[now];
    }
    for(int i = 1;i<=m;++i){
        int now;scanf("%d",&now);
        B[i] = s[now];
    }
    int L = 0,R = m,mid;
    while(L<R){
        mid = (L+R+1)/2;
        long long a = 0,b = 0,h = 1;
        bool st = false;
        for(int i = 1; i <= mid; ++i){
            a = a*1029 + A[i];
            b = b*1029 + B[i];
            h = h*1029;
        }
        if(a == b) st = true;
        for(int i = mid + 1; i <= n - (m - mid); ++i){
            a = a*1029 - h*A[i-mid] + A[i];
            if(a == b) st = true;
        }
        if(st) L = mid;
        else R = mid-1;
    }
    printf("%d\n",L);
}