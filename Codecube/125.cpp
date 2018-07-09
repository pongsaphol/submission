#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[105];
int main(){
    int n;cin>>n;
    string str;cin>>str;
    string fi1 = "SPACEBAR";
    auto ans = 0;
    while(str.find(fi1)!=string::npos){
        auto idx = str.find(fi1);
        str.erase(idx,8);
        ans++;
    }
    fi1 = "SHIFT";
    while(str.find(fi1)!=string::npos){
        auto idx = str.find(fi1);
        str.erase(idx,5);
        ans++;
    }
    for(auto now:str){
        cnt[now]++;
    }
    fi1 = "QWEASDV";
    for(auto now:fi1){
        ans += cnt[now];
    }
    cout<<ans;
}
