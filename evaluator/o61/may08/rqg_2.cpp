#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int n, x, y;

void solve(pii pos, int sz, pii del) {
    int ret = sz >> 1;
    if(ret == 1) {
        int x, y; tie(x, y) = pos;
        bool st1 = (x/2) & 1, st2 = (y/2) & 1;
        if(pos == del) printf("1 %d %d %d\n", st1 == st2 ? 2 : 3, pos.y, pos.x);
        else if(pos.x == del.x) printf("2 %d %d %d\n", st1 == st2 ? 2 : 3,  pos.y, pos.x);
        else if(pos.y == del.y) printf("3 %d %d %d\n", st1 == st2 ? 2 : 3, pos.y, pos.x);
        else printf("4 %d %d %d\n", st1 == st2 ? 2 : 3, pos.y, pos.x);
        return;
    }
    int x = pos.x+ret-1, y = pos.y+ret-1;
    swap(x, y);
    if(del.x < pos.x+ret && del.y < pos.y+ret) solve(pos, ret, del), printf("%d 1 %d %d\n", 1, x, y);
    else solve(pos, ret, pii(pos.x+ret-1, pos.y+ret-1));
    if(del.x < pos.x+ret && del.y >= pos.y+ret) solve(pii(pos.x, pos.y+ret), ret, del), printf("%d 1 %d %d\n", 2, x, y);
    else solve(pii(pos.x, pos.y+ret), ret, pii(pos.x+ret-1, pos.y+ret));
    if(del.x >= pos.x+ret && del.y < pos.y+ret) solve(pii(pos.x+ret, pos.y), ret, del), printf("%d 1 %d %d\n", 3, x, y);
    else solve(pii(pos.x+ret, pos.y), ret, pii(pos.x+ret, pos.y+ret-1));
    if(del.x >= pos.x+ret && del.y >= pos.y+ret) solve(pii(pos.x+ret, pos.y+ret), ret, del), printf("%d 1 %d %d\n", 4, x, y);
    else solve(pii(pos.x+ret, pos.y+ret), ret, pii(pos.x+ret, pos.y+ret));
}

int main() {
    scanf("%d %d %d", &n, &x, &y);
    swap(x, y);
    solve(pii(1, 1), 1<<n, pii(x, y));
}
