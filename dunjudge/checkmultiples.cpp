#include <cstdio>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    puts(n % m ? "No" : "Yes");
}