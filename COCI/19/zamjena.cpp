#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> V1, V2;

void wa() {
    puts("NE");
    exit(0);
}

bool is(char c) {
    return c >= '0' and c <= '9';
}

const int N = 1e5+5;

int P[N];

int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }

string ret[N];

int main() {
    iota(P, P+N, 0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i) V1.emplace_back(*istream_iterator<string>(cin));
    for(int i = 0; i < n; ++i) V2.emplace_back(*istream_iterator<string>(cin));
    map<string, string> M;
    vector<string> coor;
    for(int i = 0; i < n; ++i) {
        if(is(V1[i][0]) && is(V2[i][0])) if(V1[i] != V2[i]) wa();
        if(!is(V1[i][0])) coor.emplace_back(V1[i]);
        if(!is(V2[i][0])) coor.emplace_back(V2[i]);
    }
    sort(coor.begin(), coor.end());
    auto get = [&](string &s) { return upper_bound(coor.begin(), coor.end(), s) - coor.begin(); };
    for(int i = 0; i < n; ++i) {
        if(is(V1[i][0]) && is(V2[i][0])) continue;
        if(!is(V1[i][0]) && !is(V2[i][0])) {
            int u = find(get(V1[i])), v = find(get(V2[i]));
            if(ret[u] != "" and ret[v] != "" and ret[u] != ret[v]) wa();
            if(ret[v] != "") P[u] = v;
            else P[v] = u;
            continue;
        }
        if(is(V1[i][0])) swap(V1[i], V2[i]);
        int u = find(get(V1[i]));
        if(ret[u] == "") ret[u] = V2[i];
        if(ret[u] != V2[i]) wa();
    }
    puts("DA");
    
}
