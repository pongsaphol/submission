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


const int N = 6e5+5;

class edgecolor {
private:
    struct persist {
        stack<pii> stk;
        vector<int> arr;
        persist() {}
        persist(int n, int v) : arr(vector<int>(n, v)) {}
        int getT() { return (int)stk.size(); }
        int get(int x) { return arr[x]; }
        void set(int x, int v) {
            stk.emplace(x, arr[x]);
            arr[x] = v;
        }
        void rollback(int x) {
            while(stk.size() > x) {
                int x, v; tie(x, v) = stk.top(); stk.pop();
                arr[x] = v;
            } 
        }
    };
    pii find(int u) {
        if(dsu.get(u) < 0) return pii(u, par.get(u));
        pii tmp = find(dsu.get(u));
        return pii(tmp.x, tmp.y ^ par.get(u));
    }
    bool merge(int u, int v) {
        pii ru = find(u), rv = find(v);
        if(ru.x == rv.x) return (ru.y != rv.y);
        if(dsu.get(ru.x) > dsu.get(rv.x)) swap(ru, rv);
        dsu.set(ru.x, dsu.get(ru.x) + dsu.get(rv.x));
        dsu.set(rv.x, ru.x);
        par.set(rv.x, ru.y ^ rv.y ^ 1);
        return true;
    }
    int n, m;
    vector<pair<int, pii>> lsl[N], lsr[N];
    persist dsu, par;
    map<pii, int> mp;
    bool ans[N];
    void rec(int l, int r, bool can) {
        if(l == r) return void(ans[l] = can);
        int m = l + r >> 1;
        if(can) {
            bool can_l = can, can_r = can;
            int dsu_T = dsu.getT(), par_T = par.getT();
            for(int i = m; i <= r; ++i)
                for(auto x : lsr[i]) if(x.x <= l) can_l &= merge(x.y.x, x.y.y);
            rec(l, m, can_l);
            dsu.rollback(dsu_T), par.rollback(par_T);
            for(int i = l; i <= m+1; ++i) 
                for(auto x : lsl[i]) if(x.x >= r) can_r &= merge(x.y.x, x.y.y);
            rec(m+1, r, can_r);
            dsu.rollback(dsu_T), par.rollback(par_T);
        } else rec(l, m, can), rec(m+1, r, can);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        dsu = persist(n, -1), par = persist(n, 0);
        for(int i = 0, t, u, v; i < m; ++i) {
            cin >> t >> u >> v;
            if(u > v) swap(u, v);
            pii now(u, v);
            if(t) mp[now] = i;
            else {
                lsl[mp[now]].emplace_back(i-1, now);
                lsr[i-1].emplace_back(mp[now], now);
                mp.erase(now);
            }
        }
        for(auto x : mp) {
            lsl[mp[x.x]].emplace_back(m-1, x.x);
            lsr[m-1].emplace_back(mp[x.x], x.x);
        }
        rec(0, m-1, true);
        for(int i = 0; i < m; ++i) cout << (ans[i] ? "yes" : "no") << endl;
    }
};