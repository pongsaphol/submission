#include "reverse_c.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long* a = malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) 
        scanf("%lld", &a[i]);

    long long* result = (long long*)malloc(n * sizeof(long long));

    reverse(n, a, result);

    for (int i = 0; i < n; i++) {
        printf("%lld ", result[i]);
    }
    printf("\n");
    return 0;
}
