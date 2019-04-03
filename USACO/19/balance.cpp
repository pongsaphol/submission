#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 2e5+5;

class balance {
private:
    int n;
    int inp[N];
    vector<int> vl0, vl1, vr0, vr1;
    long ans = LINF;
    int t[N<<1];
    void update(int x, int v) {
        for(int i = x; i < 2*N; i += i & -i) t[i] += v;
    }
    long query(int x, long v = 0) {
        for(int i = x; i; i -= i & -i) v += t[i];
        return v;
    }
    long que1(int l, int r) {
        if(l > r) return 0;
        return query(r) - query(l-1);
    }
    long que0(int l, int r) {
        if(l > r) return 0;
        return r-l+1 - (query(r) - query(l-1));
    }
    void solve1() {
        memset(t, 0, sizeof t);
        for(int i = 1; i <= 2*n; ++i) if(inp[i]) update(i, 1);
        long cntl = 0, cntr = 0;
        for(int i = n, cnt = 0; i; --i) {
            if(inp[i]) cntl += cnt;
            else cnt++;
        }
        for(int i = 2*n, cnt = 0; i > n; --i) {
            if(inp[i]) cntr += cnt;
            else cnt++;
        }
        ans = min(ans, abs(cntl - cntr));
        long dist = 0;
        // 00010 00100 -> 00000 10100  ----> move 1 from l to r
        for(int i = 0; i < min(vl1.size(), vr0.size()); ++i) {
            cntl += que1(1, vl1[i]-1) - que0(vl1[i]+1, n);
            cntr += que0(vr0[i]+1, 2*n) - que1(n+1, vr0[i]-1);
            update(vl1[i], -1), update(vr0[i], 1);
            dist += vr0[i] - vl1[i];
            ans = min(ans, abs(cntl - cntr) + dist);
        }
    }
    void solve2() {
        memset(t, 0, sizeof t);
        for(int i = 1; i <= 2*n; ++i) if(inp[i]) update(i, 1);
        long cntl = 0, cntr = 0;
        for(int i = n, cnt = 0; i; --i) {
            if(inp[i]) cntl += cnt;
            else cnt++;
        }
        for(int i = 2*n, cnt = 0; i > n; --i) {
            if(inp[i]) cntr += cnt;
            else cnt++;
        }
        ans = min(ans, abs(cntl - cntr));
        long dist = 0;
        // 00010 10001 -> 00011 00001  ----> move 1 from r to l
        for(int i = 0; i < min(vr1.size(), vl0.size()); ++i) {
            cntl += que0(vl0[i]+1, n) - que1(1, vl0[i]-1);
            cntr += que1(n+1, vr1[i]-1) - que0(vr1[i]+1, 2*n);
            update(vl0[i], 1), update(vr1[i], -1);
            dist  += vr1[i] - vl0[i];
            ans = min(ans, abs(cntl - cntr) + dist);
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= 2*n; ++i) {
            cin >> inp[i];
            if(inp[i]) {
                if (i <= n) vl1.emplace_back(i);
                else vr1.emplace_back(i);
            } else {
                if(i <= n) vl0.emplace_back(i);
                else vr0.emplace_back(i);
            }
        }
        reverse(all(vl1)), reverse(all(vl0));
        solve1();
        solve2();
        cout << ans << endl;
    }
};
