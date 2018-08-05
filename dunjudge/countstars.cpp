#include <cstdio>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int cnt = 0;
    for(int i = 0; i < n*m; ++i) {
        char c; scanf(" %c", &c);
        if(c == '*') cnt++;
    }
    printf("%d", cnt);
}