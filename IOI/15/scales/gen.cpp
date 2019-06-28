#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

vector<pair<int, vector<int> > > que;
vector<vector<int> > perm;
int ids[5005];
int mx = 0;
int zzz;

bool dfs(int u, vector<int> vec, int lv) {
    if(vec.size() == 1) return true;
    mx = max(mx, u);
    for(int ii = 0; ii < que.size(); ++ii) {
        if(u == 0) cerr << ii << endl;
        auto& z = que[ii];
        vector<int> Mp[6];
        for(int v : vec) {
            vector<pii> val;
            for(int i = 0; i < 3; ++i) val.emplace_back(perm[v][z.y[i]], z.y[i]);
            sort(val.begin(), val.end());
            if(z.x == 0) 
                Mp[val[2].y].emplace_back(v);
            else if(z.x == 1)
                Mp[val[0].y].emplace_back(v);
            else if(z.x == 2)
                Mp[val[1].y].emplace_back(v);
            else {
                bool st = false;
                for(int i = 0; i < 3; ++i) {
                    if(val[i].x > perm[v][z.y[3]]) {
                        Mp[val[i].y].emplace_back(v);
                        st = true;
                        break;
                    }
                }
                if(!st) Mp[val[0].y].emplace_back(v);
            }
        } 
        int step = 0;
        bool st = true;
        int sum = 0;
        for(int i = 0; i < 6; ++i) {
            if(Mp[i].size() > (lv/3)) st = false;
            sum += Mp[i].size();
        }
        if(sum != vec.size()) cerr << z.x << " " << sum << " -> " << vec.size() << endl;
        assert(sum == vec.size());
        if(st) for(int i = 0; i < 6; ++i) if(Mp[i].size()) {
            step++;
            bool val = dfs(u*3 + step, Mp[i], lv / 3);
            if(val == false) {
                st = false;
                break;
            }
        }
        if(st) {
            ids[u] = ii;
            return true;
        }
    }
    return false;
}

int nth = 6;

int main() {
    memset(ids, -1, sizeof ids);
    for(int i = 0; i < (1 << nth); ++i) {
        vector<int> vec;
        for(int j = 0; j < nth; ++j) if(i >> j & 1) 
            vec.emplace_back(j);
        if(vec.size() == 3) 
            for(int j = 0; j < 3; ++j) que.emplace_back(j, vec);
        if(vec.size() == 4) {
            for(int i = 0; i < 4; ++i) {
                vector<int> ret;
                for(int j = 0; j < 4; ++j) if(i != j) ret.emplace_back(vec[j]);
                ret.emplace_back(vec[i]);
                for(int i : ret) cerr << i << ' ';
                cerr << endl;
                que.emplace_back(3, ret);
            }
        }
    }
    vector<int> now;
    for(int i = 0; i < nth; ++i) now.emplace_back(i+1);
    do {
        perm.emplace_back(now);
    } while(next_permutation(now.begin(), now.end()));
    cerr << perm.size() << " -> " << que.size() << endl;
    vector<int> zz;
    for(int i = 0; i < perm.size(); ++i) zz.emplace_back(i);
    bool haveans = dfs(0, zz, 729);
    if(haveans) cerr << "HAVE ANSWER!!!" << endl;
    cerr << "=> " << mx << endl;
    printf("{");
    for(int i = 0; i <= mx; ++i) printf("%d, ", ids[i]);
    printf("0};");
}