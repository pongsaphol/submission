#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for(int i = 1; i <= T; ++i) {
        int n, ret; cin >> n;
        for(int i = 0; i <= n; ++i) scanf("%d", &ret);
        printf("Case #%d: %d\n", i, n & 1);
        if(n & 1) puts("0.0");
    }
}