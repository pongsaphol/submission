#include "reverse.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) 
        scanf("%lld", &a[i]);

    std::vector<long long> ans = reverse(a);

    for (int i = 0; i < ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");

    return 0;
}
