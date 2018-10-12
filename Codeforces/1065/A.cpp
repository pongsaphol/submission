#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int s, a, b, c; scanf("%d %d %d %d", &s, &a, &b, &c);
        int want = s / c;
        long long sum = 0;
        sum += want;
        long long z = want / a;
        sum += z * b;
        printf("%lld\n", sum);
    }
}
