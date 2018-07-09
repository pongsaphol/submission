#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    list<int> L;
    list<int>::iterator it,it2;
    while(n--){
        int now;
        scanf("%d",&now);
        L.push_back(now);
    }
    for(it = L.begin();it!=L.end();++it){
        it2 = it;it2++;
        if(it2==L.end())break;
        if(*it>*it2&&m>=1){
            L.erase(it);
            m--;
        }
        it = it2;
        it--;
    }
    while(m>=1){
        int mx = 0;
        for(it = L.begin();it!=L.end();++it){
            mx = max(mx,*it);
        }
        for(it = L.begin();it!=L.end();++it){
            if(*it == mx){
                L.erase(it);
                break;
            }
        }
        m--;
    }
    for(it = L.begin();it!=L.end();++it){
        printf("%d ",*it);
    }
    return 0;
}
