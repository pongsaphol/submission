#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

map<int, int> M[N];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> V;
    vector<int> sum(n, 0);
    for(int i = 0; i < n; ++i) V.emplace_back(i);
    do {
        vector<bool> ret(n, true);
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; ++i) {
            queue<int> Q;
            Q.emplace(V[i]);
            set<int> S;
            while(!Q.empty()) {
                int now = Q.front(); Q.pop();
                if(S.count(now)) continue;
                S.emplace(now);
                if(now > 0) if(ret[now-1]) Q.emplace(now-1);
                if(now < n-1) if(ret[now+1]) Q.emplace(now+1);
            }
            for(auto x : S) cnt[x]++;
            ret[V[i]] = false;
        }
        //for(auto x : cnt) printf("%d ", x);
        //puts("");
        for(int i = 0; i < n; ++i) sum[i] += cnt[i], M[i][cnt[i]]++;
    } while(next_permutation(V.begin(), V.end()));
    puts("---answer---");
    for(auto x : sum) printf("%d ", x); 
    puts("");
    for(int i = 0; i < n; ++i) {
        printf("pos => %d\n", i);
        for(auto x : M[i]) {
            printf("%d %d\n", x.first, x.second);
        }
    }
}
