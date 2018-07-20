#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int z = sqrt(n);
    z += 3;
    if(n == 1) return !printf("Not Prime");
    if(n == 2) return !printf("Prime");
    for(int i = 2; i <= z; ++i) if(n % i == 0) return !printf("Not Prime");
    puts("Prime");
}