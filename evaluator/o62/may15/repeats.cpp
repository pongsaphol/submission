#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e3+5;

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }

int n, k;
char arr[N];
pii pre[N];
pii pwn[N];
pii iden(131, 133);
int ans;

int main() {
    scanf("%d", &k);
    scanf("%s", arr+1);
    pwn[0] = pii(1, 1);
    n = strlen(arr+1);
    for(int i = 1; i <= n; ++i) {
        pre[i] = add(mul(pre[i-1], iden), pii(arr[i], arr[i]));
        pwn[i] = mul(pwn[i-1], iden);
    } 
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; j += 2) {
            int z = i-1;
            int zz = i+j >> 1;
            int sz = j-z >> 1;
            if(sub(pre[j], mul(pwn[sz], pre[zz])) == sub(pre[zz], mul(pwn[sz], pre[z]))) {
                ans++;
                continue;
            }
            int l = 0, r = sz-1; 
            while(l < r) {
                int m = l + r + 1 >> 1;
                if(sub(pre[i+m-1], mul(pwn[m], pre[i-1])) == sub(pre[zz+m], mul(pwn[m], pre[zz]))) l = m;
                else r = m-1;
            }
            int lbound = i+l;
            l = 0, r = sz-1;
            while(l < r) {
                int m = l + r + 1 >> 1;
                if(sub(pre[zz], mul(pwn[m], pre[zz-m])) == sub(pre[j], mul(pwn[m], pre[j-m]))) l = m;
                else r = m-1;
            } 
            int rbound = zz-l;
            if(lbound == rbound && k >= 1) {
                ans++;
                continue;
            }
            rbound--;
            if(lbound == rbound && k >= 2) {
                ans++;
                continue;
            }
            if(sub(pre[rbound], mul(pwn[rbound-lbound], pre[lbound])) == sub(pre[sz+rbound], mul(pwn[rbound-lbound], pre[sz+lbound])) && k >= 2) {
                ans++;
                continue;
            }
            if(n <= 200) {
                int mismatch = 0;
                int zz = i+j >> 1;
                int sz = (j - (i-1)) >> 1;
                for(int z = i; z <= zz; ++z) if(arr[z] != arr[z+sz]) mismatch++;
                if(mismatch <= k) ans++;
            }
        }
    }
    printf("%d\n", ans);
}