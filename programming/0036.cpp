#include <bits/stdc++.h>
#define FOR(i,a,n) for(int i = a;i<n;++i)
#define REP(i,a,n) for(int i = a-1;i>=n;--i)

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long k;
    cin>>k;
    int l = k/2;
    double ans = 1;
    FOR(i,0,l){
        ans*=k-i;
        ans/=l-i;
    }
    long long ans2 = round(ans);
    if(k % 2 == 1)
        ans2 *= 2;
    if(k == 1)
        ans2 = 2;

    cout<<ans2;
}

