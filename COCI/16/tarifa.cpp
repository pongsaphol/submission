#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n; scanf("%d %d", &x, &n);
    x *= n+1;
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        x -= ret;
    }
    printf("%d\n", x);
}