#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) printf("%c", (i ^ j) & 1 ? 'x' : 'o');
        puts("");
    }
}