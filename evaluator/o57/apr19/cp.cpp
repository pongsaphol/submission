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

const int N = 1e5+5;

class cp {
private:
    int n, m;
    int pos[N], tmp[N], sa[N], lcp[N<<1];
    char A[N];
    vector<pair<pii, int> > vec;
    void suffix_array() {
        pos[n] = -1;
        for(int i = 0; i < n; i == 0 ? i++ : i <<= 1) {
            for(int j = 0; j < n; ++j) vec[j].x.y = pos[vec[j].y+i > n ? n : vec[j].y+i];
            sort(all(vec));
            for(int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + (vec[i].x != vec[i-1].x);
            for(int i = 0; i < n; ++i) vec[i].x.x = pos[vec[i].y] = tmp[i];
        }
        for(int i = 0; i < n; ++i) sa[pos[i]] = i;
    }
    void solve_lcp() {
        int k = 0;
        for(int i = 0; i < n; ++i) if(pos[i] != n-1) {
            for(int j = sa[pos[i]+1]; A[i+k] == A[j+k];) k++;
            lcp[pos[i]+n] = k;
            if(k) k--;
        } else k = 0;
    }
    int get(int l, int r) {
        int mn = 1e9;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) mn = min(mn, lcp[l++]);
            if(r & 1) mn = min(mn, lcp[--r]);
        }
        return mn;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        cin >> A;
        for(int i = 0; i < n; ++i) vec.emplace_back(pii(A[i], 0), i);
        suffix_array();
        solve_lcp();
        for(int i = n-1; i; --i) lcp[i] = min(lcp[i<<1], lcp[i<<1|1]);
        set<int> S; S.emplace(pos[0]);
        for(int i = 0, a, b; i < m; ++i) {
            cin >> a >> b; b = pos[b-1];
            if(a == 2) {
                int mx = 0;
                auto it = S.lower_bound(b);
                if(it != S.end()) {
                    int v = *it;
                    if(v == b) mx = n - sa[b];
                    else mx = max(mx, get(b, v));
                }
                if(it != S.begin()) {
                    it--;
                    int v = *it;
                    mx = max(mx, get(v, b));
                }
                cout << mx << endl;
            } else S.emplace(b);
        }
    }
};