#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    list<int> L;list<int>::iterator it,it2,it3;
    for(int i = 1;i<=n;++i){
        int now;scanf("%d",&now);
        L.push_back(now);
    }
    int P = n/2;
    int sum = 0;
    for(int i = 0;i<P;++i){
        int mn = 0;
        it2 = L.end();it2--;
        for(it = L.begin();it!=it2;++it){
            it3 = it;it3++;
            mn = max(mn,abs(*it-*it3));
        }
       // printf("%d\n",mn);
        for(it = L.begin();it!=it2;++it){
            it3 = it;it3++;
            if(abs(*it-*it3)==mn){
                L.erase(it);L.erase(it3);
                sum+=mn;
                break;
            }
        }
    }
    printf("%d\n",sum);
}
