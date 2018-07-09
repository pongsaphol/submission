#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <iostream>
using namespace std;
map<int,int> M[8];
int main(){
    int T;
    scanf("%d",&T);
    long long sum = 0;
    while(T--){
        char a[4];scanf("%s",a);
        int A[8];
        A[0] = a[0]-'0',A[1] = a[1]-'0',A[2] = a[2]-'0';
        A[3] = A[0]*10+A[1],A[4] = A[0]*10+A[2],A[5] = A[1]*10+A[2];
        A[6] = A[0]*100+A[1]*10+A[2];
        int now = 0;
        for(int i = 0;i<7;++i){
            if(i>=3&&i<=5)now-=M[i][A[i]];
            else now+=M[i][A[i]];
        }
        sum+=now;
        for(int i = 0;i<7;++i){
            M[i][A[i]]++;
        }
    }
    printf("%lld\n",sum);
}
