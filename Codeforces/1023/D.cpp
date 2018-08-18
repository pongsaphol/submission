#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, q;
int A[N], t[N<<1];
int query(int l, int r) {
    int ans = 1e9;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = min(ans, t[l++]);
        if (r&1) ans = min(ans, t[--r]);
    }
    return ans;
}
int mnp[N], mxp[N];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; ++i)
        mnp[i] = 1e9;
    int zeropos = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if (A[i] == 0)
            zeropos = i;
        if (A[i] == 0 && (i != 0 && A[i-1] != 0))
            A[i] = A[i-1];
    }
    for (int i = n-1; i >= 0; --i) {
        if (A[i] == 0 && (i != n-1 && A[i+1] != 0))
            A[i] = A[i+1];
        if (A[i] == 0)
            A[i] = q;
        t[n+i] = A[i];
        mnp[A[i]] = min(mnp[A[i]], i);
        mxp[A[i]] = max(mxp[A[i]], i);
    }
    if (mnp[q] == 1e9) {
        if (zeropos == -1) return !printf("NO\n");
        mnp[q] = mxp[q] = zeropos;
        t[n+zeropos] = A[zeropos] = q;
    }
    for (int i = n-1; i > 0; --i)
        t[i] = min(t[i<<1], t[i<<1|1]);
    for (int i = 1; i <= q; ++i) {
        int q = query(mnp[i], mxp[i]);
        if (q < i) return !printf("NO\n");
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", A[i]);

    return 0;
}