#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> V;
    while(n--){
        int a;
        scanf("%d",&a);
        V.push_back(a);
    }
    sort(V.begin(),V.end(),greater<int>());
    int idx = 0;
    long long sum = 0;
    while(idx<V.size()){
        sum+=V[idx];
        idx+=k;
    }
    printf("%lld\n",sum);
}
