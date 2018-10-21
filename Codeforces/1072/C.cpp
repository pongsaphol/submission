#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

#define long long long 
bool have[N];

int main() {
    int a, b; scanf("%d %d", &a, &b);
    long z = 0;
    while(1) {
        if((z+1) * (z) / 2 > (a + b)) {
            z--;
            break;
        }
        z++;
    }
    vector<int> v[2];
    bool swp = false;
    if(a < b) swap(a, b), swp = true;
    for(int i = z; i; --i) {
        if(b >= i) b -= i, v[swp].emplace_back(i), have[i] = true;
    }
    for(int i = 1; i <= z; ++i) if(!have[i]) v[swp^1].emplace_back(i);
    printf("%d\n", (int)v[1].size());
    for(auto x : v[1]) printf("%d ", x);
    puts("");
    printf("%d\n", (int)v[0].size());
    for(auto x : v[0]) printf("%d ", x);
    puts("");
}
