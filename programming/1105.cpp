#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main(){
    int T,k;
    scanf("%d%d",&T,&k);
    vector<int> V;
    while(T--){
        int n;
        scanf("%d",&n);
        V.push_back(n);
    }
    sort(V.begin(),V.end(),greater<int>());
    printf("%d\n",V[k-1]);
}
