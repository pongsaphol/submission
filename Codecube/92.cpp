#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double dp[100005];

int main(){
    for(int i = 1;i<=100000;++i){
        dp[i] = dp[i-1]+log10(i);
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%d\n",(int)(dp[n])+1);
    }
}
