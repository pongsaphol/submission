#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main(){
    set<string> S;
    int T;cin>>T;
    while(T--){
        string str;
        cin>>str;
        S.insert(str);
    }
    set<string>::iterator it;
    for(it = S.begin();it!=S.end();++it){
        cout<<*it<<endl;
    }
}
