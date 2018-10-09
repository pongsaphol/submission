#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct coorh {
    size_t operator()(const pii &a) const {
        return a.x + a.y;
    }
};

int n, m;

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> str;
    for(int i = 0; i < n; ++i) {
        string now; cin >> now;
        str.emplace_back(now);
    }
    sort(all(str));
    unordered_map<pii, vector<int>, coorh> hr(20000000);
    unordered_map<pii, pii, coorh> hl(20000000);
    for(int i = 0; i < n; ++i) {
        int len = str[i].size();
        pii hashl, hashr;
        for(int j = 0; j < len; ++j) {
            hashl = add(mul(hashl, pii(131, 133)), pii(str[i][j], str[i][j]));
            if(hl.count(hashl)) hl[hashl].y = i;
            else hl[hashl] = pii(i, i);
        }
        for(int j = len-1; ~j; --j) 
            hashr = add(mul(hashr, pii(131, 133)), pii(str[i][j], str[i][j])), hr[hashr].emplace_back(i);
    }
    for(int i = 0; i < m; ++i) {
        string a, b; cin >> a >> b;
        pii hashl, hashr;
        for(int j = 0; j < a.size(); ++j) 
            hashl = add(mul(hashl, pii(131, 133)), pii(a[j], a[j]));
        for(int j = b.size()-1; ~j; --j) 
            hashr = add(mul(hashr, pii(131, 133)), pii(b[j], b[j]));
        if(!hl.count(hashl)) {
            puts("0");
            continue;
        }
        int l = hl[hashl].x, r = hl[hashl].y;
        int dis = upper_bound(all(hr[hashr]), r) - lower_bound(all(hr[hashr]), l);
        printf("%d\n", dis);
    }
}
