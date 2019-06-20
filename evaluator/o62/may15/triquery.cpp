#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define iii tuple<int, int, long>
#define long long long
using namespace std;

const int N = 2e3+5;

int n, m;
long pre[N][N], tri[N][N], arr[N][N];
vector<tuple<int, int, int, long> > que;

int main() {
    scanf("%d %d", &n, &m);
    int sq = sqrt(m);
    vector<iii> vec;
    int state = 0;
    for(int i = 1; i <= m; ++i) {
        if(vec.size() == 1000) {
            vec.clear();
            for(int i = 1; i <= n; ++i) {
                for(int j = n; j; --j) {
                    pre[i][j] = pre[i-1][j] + pre[i][j+1] - pre[i-1][j+1] + arr[i][j];
                    tri[i][j] = tri[i-1][j+1] + pre[i][j] - pre[i-1][j];
                }
            }
        }
        int t, x, y;
        long c;
        scanf("%d %d %d %lld", &t, &x, &y, &c);
        if(t == 2) {
            c /= 2;
            vec.emplace_back(x, y, c - arr[x][y]);
            arr[x][y] = c;
        } else {
            long ans = tri[x][y-c+1] - tri[x-c][y+1] - (pre[x][y+1] - pre[x-c][y+1]);
            for(auto node : vec) {
                int a, b; long v; tie(a, b, v) = node;
                if(a <= x && a >= x-c+1 && b <= y && b >= y-c+1) {
                    if(x-a+y-b <= c-1) ans += v;
                }
            }
            if(--c) {
                ans += tri[x][y-c+1] - tri[x-c][y+1] - (pre[x][y+1] - pre[x-c][y+1]);
                for(auto node : vec) {
                    int a, b; long v; tie(a, b, v) = node;
                    if(a <= x && a >= x-c+1 && b <= y && b >= y-c+1) {
                        if(x-a+y-b <= c-1) ans += v;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
}