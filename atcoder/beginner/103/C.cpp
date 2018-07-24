#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    scanf("%d", &n);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        ans += ret - 1;
    }
    printf("%d\n", ans);
}