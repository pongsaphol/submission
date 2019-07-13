#include <bits/stdc++.h>
using namespace std;

int n = 5;

int main() {
    srand(time(NULL));
    printf("%d\n", 2*n + 1);
    printf("-1 0 ");
    for(int i = 1; i < n; ++i) printf("%d ", i);
    printf("0 ");
    for(int i = 1; i < n; ++i) printf("%d ", n+i);
    printf("\n0 ");
    for(int i = 1; i < (2*n + 1); ++i) printf("%d ", (rand() % 50) + 1);
    printf("\n0 ");
    for(int i = 1; i < (2*n + 1); ++i) printf("%d ", (rand() % 50) + 1);
    printf("\n");
}