#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e6;

int n, x;
int t[N][2], ptr;

void update(int u, int s) {
    int p = 0; 
    for(int i = 29; ~i; --i) {
        bool z = u >> i & 1;
        if(t[p][z]) p = t[p][z];
        else p = t[p][z] = ++ptr;
    }
    if(t[p][0] == 0) t[p][0] = s;
    else t[p][0] = max(t[p][0], s);
}

pii query(int u) {
    int p = 0, sum = 0;
    for(int i = 29; ~i; --i) {
        bool z = u >> i & 1;
        if(t[p][z^1]) sum += (1 << i), p = t[p][z^1];
        else p = t[p][z];
    }
    return pii(sum, t[p][0]);
}

int main() {
    scanf("%d %d", &n, &x);
    int pref = 0;
    update(pref, 1);
    int mx = 0, mni = n, k;
    for(int i = 1, ret; i <= n; ++i) {
        scanf("%d", &ret);
        pref ^= ret;
        pii z = query(pref);
        if(z.x > mx) 
            mx = z.x, mni = z.y, k = i-z.y+1;
        if(z.x == mx && mni > z.y) mni = z.y, k = i-z.y+1;
        update(pref, i+1);
    } 
    printf("%d %d\n", mni, k);
}
