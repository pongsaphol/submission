#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5;
class lnode{
public:
    int key;
    lnode* prev;
    lnode* next;
    lnode(int key){
        this->key = key;
        prev = NULL;
        next = NULL;
    }
};
lnode* ar[MAX+5];
int arr[MAX+5],FT[MAX+5];
void update(int idx,int val){
    while(idx<=MAX){
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
    scanf("%d",arr+1);
    lnode* root = new lnode(arr[1]);
    ar[arr[1]] = root;
    lnode* iter = root;
    for(int i = 2;i<=n;++i){
        scanf("%d",arr+i);
        iter->next = new lnode(arr[i]);
        iter->next->prev = iter;
        iter = iter->next;
        ar[arr[i]] = iter;
    }
    iter->next = root;
    root->prev = iter;
    for(int i = 1;i<=MAX;++i)FT[i] = i&(-i);
    int loop = n/2;
    for(int i = 0;i<loop;++i){
        int sz = (n-2*i+1)/2;
        int L = 1,R = MAX,mid;
        while(L<R){
            mid = (L+R)/2;
            int num = query(mid);
            if(num<sz){
                L = mid+1;
            }else{
                R = mid;
            }
        }
       // printf("%d %d\n",R,ar[R]->next->key);
        update(R,-1);
        update(ar[R]->next->key,-1);
        lnode* todel = ar[R]->prev;
        lnode* todel2 = ar[R]->next->next;
        todel->next = todel2;
        todel2->prev = todel;
    }
    for(int i = 1;i<=n;++i){
        if(FT[i]){
            printf("%d\n",i);
            return 0;
        }
    }
}
