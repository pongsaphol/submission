#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    int sum = 0;
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        sum += ret;
    }
    printf("%d\n", sum / n);
}