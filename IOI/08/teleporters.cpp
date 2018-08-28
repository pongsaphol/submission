#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e6+5;

int n, m, V[N], val[N], neibour[N], Com[N], psz, pz1;
bool Check[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        neibour[u] = v, neibour[v] = u;
        V[u]++, V[v]++;
    }
    for(int i = 1; i < N; ++i) {
        V[i] += V[i-1];
        if(V[i] != V[i-1]) Com[pz1++] = i;
    }
    int cnt = 0, p = 0; Check[0] = true;
    while(p != (n<<1)) Check[p = V[neibour[Com[p]]]] = true, cnt++;
    for(int i = 1; i <= (n<<1); ++i) if(!Check[i]) {
        int u = i, sz = 0; Check[u] = true;
        do Check[u = V[neibour[Com[u]]]] = true, sz++; while(u != i);
        val[++psz] = sz;
    }
    sort(val+1, val + psz + 1, greater<int>()); for(int i = 1; i <= psz; ++i) val[i] += val[i-1]; 
    cnt += val[min(psz, m)] + 2 * min(psz, m);
    if(m > psz) m -= psz, cnt += ((m>>1)<<2) + (m & 1);
    printf("%d\n", cnt);
}
