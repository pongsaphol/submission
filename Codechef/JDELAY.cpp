#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        int cnt = 0;
        for(int i = 0, a, b; i < n; ++i) {
            scanf("%d %d", &a, &b);
            cnt += b - a > 5;
        }
        printf("%d\n", cnt);
    }
}
