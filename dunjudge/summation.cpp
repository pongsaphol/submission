#include <cstdio>
#include <cstdlib>

int main() {
    int sum = 0, n; scanf("%d", &n);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        sum += abs(ret);
    }
    printf("%d\n", sum);
}