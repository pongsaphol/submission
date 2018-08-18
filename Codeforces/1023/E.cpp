#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
char ans[N];

bool ask(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    char ans[100];
    scanf(" %s", ans);
    return ans[0] == 'Y';
}

int main()
{
    scanf("%d", &n);
    int x = 1, y = 1;
    for (int i = 1; i <= n-1; ++i) {
        if (ask(x, y+1, n, n)) {
            ans[i] = 'R';
            ++y;
        } else {
            ans[i] = 'D';
            ++x;
        }
    }
    int px = x, py = y;
    x = n, y = n;
    for (int i = 2*(n-1); i >= n; --i) {
        if (ask(1, 1, x-1, y)) {
            --x;
            ans[i] = 'D';
        } else {
            --y;
            ans[i] = 'R';
        }
    }
    assert(px == x and py == y); 
    printf("! %s\n", ans+1);
    fflush(stdout);

    return 0;
}