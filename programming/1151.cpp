#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> V;
    int n;
    scanf("%d",&n);
    vector<int>::iterator it;
    while(n--){
        int k;scanf("%d",&k);
        it = lower_bound(V.begin(),V.end(),k);
        if(it==V.end())V.push_back(k);
        else *it = k;
    }
    printf("%d\n",V.size());

}
