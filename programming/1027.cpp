#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <cstring>
using namespace std;
char arr[10005];
int point[10];
bool st[10];
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}
int main(){
    int cnt = 7;
    while(1){
        scanf("%s",arr);
        if(arr[0]=='!')break;
        int len = strlen(arr);
        int cache[10];
        memset(cache,0,sizeof cache);
        for(int i = 0;i<len;++i){
            int now = arr[i]-'A';
            point[now]++;
        }
        int mn = 1e9;
        for(int i = 0;i<7;++i)point[i] = min(point[i],30000);
        for(int i = 0;i<7;++i)if(!st[i])mn = min(mn,point[i]);
        int idx = -1;
        for(int i = 0;i<7;++i){
            if(!st[i]&&mn == point[i]){
                if(idx==-1) idx = i;
                else idx = 1e9;
            }
        }
        //printf("-->%d\n",mn);
        if(cnt==1)continue;
        if(idx!=1e9&&idx!=-1){
            cnt--;
            st[idx] = true;
        }
    }
    vector<pair<int,int> > V;
    for(int i = 0;i<7;++i)if(!st[i])V.push_back(make_pair(point[i],i));
    sort(V.begin(),V.end(),cmp);
    printf("%d\n",V.size());
    for(auto& now:V){
        printf("%c %d\n",now.second+'A',now.first);
    }
}
