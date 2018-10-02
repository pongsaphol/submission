#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>

void make_uni(vector<int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

int get(vector<int> &v, int d) {
    return lower_bound(v.begin(), v.end(), d) - v.begin();
}

int getu(vector<int> &v, int d) {
    return upper_bound(v.begin(), v.end(), d) - v.begin();
}

int n, k;
vector<iii> que;

int main() {
    scanf("%d %d", &n, &k);
    vector<int> c1;
    for(int i = 0, a, b, c; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        c1.emplace_back(c);
        que.emplace_back(a, b, c);
    }
    make_uni(c1);
    vector<vector<int> > c2(c1.size());
    for(int i = 0, a, b, c; i < n; ++i) {
        tie(a, b, c) = que[i];
        c2[get(c1, c)].emplace_back(a+b);
    }
    for(int i = 0; i < c2.size(); ++i) make_uni(c2[i]);
    vector<vector<vector<int> > > c3(c2.size());
    for(int i = 0; i < c3.size(); ++i) c3[i].resize(c2[i].size());
    for(int i = 0, a, b, c; i < n; ++i) {
        tie(a, b, c) = que[i];
        int k1 = get(c1, c);
        int k2 = get(c2[k1], a+b);
        for(int i = k2+1; i; i -= i & -i) c3[k1][i-1].emplace_back(a);
    }
    for(int i = 0; i < c3.size(); ++i) for(int j = 0; j < c3[i].size(); ++j) make_uni(c3[i][j]);
    vector<vector<vector<int> > > t(c3.size());
    for(int i = 0; i < c3.size(); ++i) {
        t[i].resize(c3[i].size());
        for(int j = 0; j < t[i].size(); ++j) t[i][j].resize(c3[i][j].size());
    }
    sort(que.begin(), que.end(), [&](const iii &a, const iii &b) { return get<0>(a) < get<0>(b); });
    long long sum = 0;
    for(auto &x : que) {
        int a, b, c; tie(a, b, c) = x;
        for(int l = get(c1, c-k), r = getu(c1, c+k); l != r; ++l) 
            for(int i = get(c2[l], a)+1; i <= c2[l].size(); i += i & -i) 
                for(int j = get(c3[l][i-1], a-b)+1; j <= c3[l][i-1].size(); j += j & -j) 
                    sum += t[l][i-1][j-1];
        int p = get(c1, c);
        for(int i = get(c2[p], a+b)+1; i; i -= i & -i) 
            for(int j = get(c3[p][i-1], a)+1; j; j -= j & -j) 
                t[p][i-1][j-1]++; 
    }
    printf("%lld\n", sum);
}
