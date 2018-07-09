#include <bits/stdc++.h>
#define FOR(i,a,n) for(int i = a;i<n;++i)
using namespace std;
class lnode{
public:
    int key;
    lnode* next;
    lnode* before;
    lnode(int key){
        this->key = key;
        next = NULL;
    }
};

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    lnode* root = new lnode(1);
    lnode* cond = new lnode(2);
    root->next = cond;
    cond->before = root;
    FOR(i,3,a+1){
        cond->next = new lnode(i);
        (cond->next)->before = cond;
        cond = cond->next;
    }
    cond->next = root;
    root->before = cond;
    FOR(i,0,a){
        //cout<<"debug "<<i<<":"<<(b%(a-i))<<endl;;
        FOR(j,0,(b%(a-i))){
            cond = cond->next;
        }
        if(b%(a-i)==0){
            cond = cond->before;
        }
        (cond->before)->next = cond->next;
        (cond->next)->before = cond->before;
        printf("%d\n",cond->key);
    }

}

