#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 3e5;
int FT[MAX+5],arr[MAX+5],rea[MAX+5];

void update(int idx,int val){
    while(idx<=300000){
        FT[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int val = 0;
    while(idx>=1){
        val+=FT[idx];
        idx-=idx&(-idx);
    }
    return val;
}
int main(){
    int n;
    scanf("%d",&n);
    int sum = 0;
    vector<pair<int,int> > V;
    for(int i = 1;i<=n;++i){
        scanf("%d",arr+i);sum+=arr[i];
        V.push_back(make_pair(arr[i],i));
    }
    sort(V.begin(),V.end(),greater<pair<int,int> >());
    for(int i = 1;i<=n;++i){
        update(i,V[i-1].first);
        rea[V[i-1].second] = i;
    }
    for(int i = 1;i<=n;++i){
        update(rea[i],-arr[i]);
        int tomore = (sum/2+1)-arr[i];
        //printf("%d %d\n",i,tomore);
        int L = 1,R = MAX;
        unsigned int mid;
        while(L<R){
            mid = ((unsigned int)L+R)/2;
            int num = query(mid);
            if(num<tomore){
                L = mid+1;
            }else{
                R = mid;
            }
        }
        if(R>rea[i])R--;
        printf("%d\n",R);
        update(rea[i],arr[i]);
    }
}
