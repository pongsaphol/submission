#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define x first
#define y second

const int N = 1e6+5;

int n, l, q;
pii A[N];
long ts[2][N], tf[2][N];

void update(long t[], int x, int v) {
    x++;
    for(; x <= l; x += x & -x) t[x] += v;
}

long query(long t[], int x) {
    long val = 0;
    x++;
    for(; x > 0; x -= x & -x) val += t[x];
    return val;
}

long que(long t[], int a, int b) {
    return query(t, b) - query(t, a);
}

long tod[N];

int main() {
    scanf("%d %d %d", &n, &l, &q);
    for(int i = 0; i < n; ++i) {
        A[i] = pii(0, 0);
        update(ts[0], A[i].x, A[i].x), update(tf[0], A[i].x, 1);
        tod[l]++;
    }
    for(int i = 0, a, b; i < q; ++i) {
        char c; scanf(" %c", &c);
        if(c == 's') {
            scanf("%d %d", &a, &b);
            update(ts[A[a].y], A[a].x, -A[a].x);
            update(tf[A[a].y], A[a].x, -1);
            if(A[a].y) tod[A[a].x]--;
            else tod[l-A[a].x]--;
            A[a].x = (A[a].x + (A[a].y ? b : -b) + l) % l;
            update(ts[A[a].y], A[a].x, A[a].x);
            update(tf[A[a].y], A[a].x, 1);
            if(A[a].y) tod[A[a].x]++;
            else tod[l-A[a].x]++;
        } else if(c == 'f') {
            scanf("%d", &a);
            update(ts[A[a].y], A[a].x, -A[a].x);
            update(tf[A[a].y], A[a].x, -1);
            if(A[a].y) tod[A[a].x]--;
            else tod[l-A[a].x]--;
            A[a].x = l - A[a].x, A[a].y ^= 1;
            if(A[a].x == l) A[a].x = 0;
            update(ts[A[a].y], A[a].x, A[a].x);
            update(tf[A[a].y], A[a].x, 1);
            if(A[a].y) tod[A[a].x]++;
            else tod[l-A[a].x]++;
        } else {
            long a;
            scanf("%lld", &a);
            long sum = 1ll * tod[a] * l;
            if(a == l) a = 0;
            sum += que(ts[0], -1, l-a-1) + que(tf[0], -1, l-a-1) * (a);
            sum += que(ts[0], l-a-1, l-1) - que(tf[0], l-a-1, l-1) * (l - a);
            sum += que(ts[1], -1, a-1) + que(tf[1], -1, a-1) * (l - a);
            sum += que(ts[1], a-1, l-1) - que(tf[1], a-1, l-1) * (a);
            printf("%lld\n", sum);
        }
    }
}
