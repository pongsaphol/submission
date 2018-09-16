#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

int n, m, cnt[N];
char buff[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", buff);
        for(int j = 0; j < m; ++j) cnt[j] += (buff[j] == '1');
    }
    int mx = 0;
    for(int j = 0; j < m; ++j) printf("%d ", cnt[j]);
    puts("");
    for(int i = 0; i < m; ++i) {
        int mh = n;
        for(int j = i; j < m; ++j) {
            mh = min(mh, cnt[j]);
            mx = max(mx, (j-i+1) * mh);
        }
    }
    printf("%d\n", mx);
}
