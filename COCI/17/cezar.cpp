#include <bits/stdc++.h>
using namespace std;

int cnt[105];

int main() {
    fill_n(cnt, 105, 4);
    int z = 21;
    cnt[10] += 8;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int ret; cin >> ret;
        z -= ret;
        cnt[ret]--;
    }
    int c1 = 0, c2 = 0;
    for(int i = 2; i <= z; ++i) c1 += cnt[i];
    for(int i = z+1; i <= 11; ++i) c2 += cnt[i];
    puts(c1 > c2 ? "VUCI" : "DOSTA");
}