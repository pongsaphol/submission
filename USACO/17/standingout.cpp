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

class standingout {
private:
    int n, len;
    string str;
    string inp[N];
    int pos[N], tmp[N], sa[N], lcp[N];
    void solve_sa() {
        len = str.size();
        for(int i = 0; i < len; ++i) sa[i] = i, pos[i] = str[i];
        for(int gap = 1; ; gap <<= 1) {
            auto cmp = [&](int i, int j) {
                if(pos[i] != pos[j]) return pos[i] < pos[j];
                i += gap, j += gap;
                return (i < len && j < len ? pos[i] < pos[j] : i > j);
            };
            sort(sa, sa+len, cmp);
            for(int i = 1; i < len; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
            for(int i = 0; i < len; ++i) pos[sa[i]] = tmp[i];
            if(tmp[len-1] == len-1) break;
        }
//        for(int i = 0; i < len; ++i) {
//            for(int j = sa[i]; j < len; ++j) cout << str[j];
//            cout << endl;
//        }
    }
    int t[N<<1];
    void solve_lcp() {
        for(int i = 0, k = 0; i < len; ++i) if(pos[i] != len-1) {
            for(int j = sa[pos[i]+1]; i+k < len && j+k < len && str[i+k] == str[j+k];) k++;
            lcp[pos[i]] = t[pos[i]+len] = k;
            if(k) k--;
        } else k = 0;
//        for(int i = 0; i < len; ++i) cout << lcp[i+len] << endl;
        for(int i = len-1; i; --i) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    int col[N], pref[N], pf[N], sf[N];
    long ans[N];
    int get(int l, int r) {
        int mn = INF;
        for(l += len, r += len; l < r; l >>= 1, r >>= 1) {
            if(l & 1) mn = min(mn, t[l++]);
            if(r & 1) mn = min(mn, t[--r]);
        }
        return mn == INF ? 0 : mn;
    }
    int last[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        str = "#";
        for(int i = 1; i <= n; ++i) {
            cin >> inp[i];
            str = str + inp[i] + "#";
            pref[i] = pref[i-1] + inp[i].size() + 1;
            for(int j = pref[i-1]+1; j < pref[i]; ++j) col[j] = i;
        }
        solve_sa();
        solve_lcp();
//        for(int i = 0; i < len; ++i) {
//            for(int j = sa[i]; j < len; ++j) cerr << str[j];
//            cerr << ' ' << col[sa[i]] << endl;
//        }
        memset(last, -1, sizeof last);
        for(int i = 0; i < len; ++i) pf[i] = i ? (col[sa[i]] == col[sa[i-1]] ? (pf[i-1]+1) : 1) : 1;
        for(int i = len-1; ~i; --i) sf[i] = i != len-1 ? (col[sa[i]] == col[sa[i+1]] ? (sf[i+1]+1) : 1) : 1;
        for(int i = 0; i < len; ++i) if(col[sa[i]]) {
            int samepref = max(get(i-pf[i], i), get(i, i+sf[i]));
            if(last[col[sa[i]]] != -1) samepref = max(samepref, get(last[col[sa[i]]], i));
//            cerr << samepref << endl;
            int val = max(0, pref[col[sa[i]]] - sa[i] - samepref);
//            cerr << "->" << val << endl;
            ans[col[sa[i]]] += val;
            last[col[sa[i]]] = i;
        }
        for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
    }
};