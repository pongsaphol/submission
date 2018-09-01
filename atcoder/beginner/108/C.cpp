#include <bits/stdc++.h>
using namespace std;

int c1, c2;
int n, k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        if(i % k == 0) c1++;
        if(k % 2 == 0) {
            int z = k / 2;
            if(i % k == z) c2++;
        }
    }
    printf("%lld\n", 1ll * c1 * c1 * c1 + 1ll * c2 * c2 * c2);
}
