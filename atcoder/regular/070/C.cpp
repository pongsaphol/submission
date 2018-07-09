#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int l = 1, r = 50000;
    while(l < r) {
        int m = l + r >> 1;
        int val = (1ll * m * (m + 1)) >> 1;
        if(val >= n) r = m;
        else l = m + 1;
    }
    printf("%d\n", r);
}