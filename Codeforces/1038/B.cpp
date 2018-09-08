#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    if(n == 1 || n == 2) return !printf("No");
    puts("Yes");
    printf("%d ", n-2);
    for(int i = 2; i < n; ++i) printf("%d ", i);
    puts("");
    printf("2 1 %d\n", n);
}
