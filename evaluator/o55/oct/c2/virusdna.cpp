#include <bits/stdc++.h>
using namespace std;

const int N = 1<<21;

int n, m;
int t[2][N+1];

void update(int t[], int x, int v) {
    for(; x <= N; x += x & -x) t[x] += v;
}

int query(int t[], int x) {
    int sum = 0;
    for(; x > 0; x -= x & -x) sum += t[x];
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) update(t[0], 2*i-1, 1);
    while(m--) {
        char c; scanf(" %c", &c);
        int x, y;
        if(c == 'd') {
            scanf("%d", &x), x++; 
            int l = 1, r = N;
            int v = 0;
            while(l < r) {
                int m = l + r >> 1;
                if(t[0][m] + v >= x) r = m;
                else l = m + 1, v += t[0][m];
            }
            update(t[0], r, -1);
            update(t[1], r, r & 1 ? 1 : -1);
        } else if(c == 'g') {
            scanf("%d", &x), x++; 
            int l = 1, r = N;
            int v = 0;
            while(l < r) {
                int m = l + r >> 1;
                if(t[0][m] + v >= x) r = m;
                else l = m + 1, v += t[0][m];
            }
            if(r & 1) r++;
            update(t[0], r, 1);
            update(t[1], r, 1);
        } else {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(t[1], 2*y-1) - query(t[1], 2*x-2)); 
        }
    }
}
