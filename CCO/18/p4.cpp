#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ret; scanf("%d", &ret);
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    int l1 = 1, r1 = n, l2 = 1, r2 = m;
    while(l1 < r1 || l2 < r2) {
        int m1 = (l1 + r1) >> 1, m2 = (l2 + r2) >> 1;
        int nval = query(m1, m2);
        if(l1 < r1) {
            if(query(m1+1, m2) >= nval) r1 = m1;
            else l1 = m1+1;
        }
        if(l2 < r2) {
            if(query(m1, m2+1) >= nval) r2 = m2;
            else l2 = m2+1;
        }
    }
    printf("! %d\n", query(r1, r2));
    fflush(stdout);
}
