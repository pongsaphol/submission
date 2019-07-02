/*
K bound is log3(N)
it mean in any level I will divide in 3 group, for each group size not greater than 3^k
for group "YES", "MAYBE", "NO" 
let N is size on this level
and lv is N/3 (size of next level)
for i in [0, 2*lv) 
if index is even I will group it "YES" and add i to asking
if index is odd I will group it "MAYBE" and add i-1 to asking
for [2*lv, N) I will group it "NO"
if grader return name of any group I will recursive that group
*/
#include <bits/stdc++.h>
using namespace std;

char str[20];
int n, m;

void rec(vector<int> vec, int lv) {
    if(vec.size() == 1) {
        printf("0 %d\n", vec[0]);
        fflush(stdout);
        return;
    }
    if(vec.size() <= lv) return void(rec(vec, lv/3));
    vector<int> ret[3];
    set<int> que;
    int bound = min((int)vec.size() / 2, lv);
    for(int i = 0; i < 2*bound; ++i) {
        if(i & 1) ret[1].emplace_back(vec[i]), que.emplace(vec[i] - 1);
        else ret[0].emplace_back(vec[i]), que.emplace(vec[i]);
    }
    for(int i = 2*bound; i < vec.size(); ++i) ret[2].emplace_back(vec[i]);
    printf("%d ", (int)que.size());
    for(int v : que) printf("%d ", v);
    printf("\n");
    fflush(stdout);
    scanf("%s", str);
    if(str[0] == 'Y') rec(ret[0], lv / 3);
    else if(str[0] == 'B') rec(ret[1], lv / 3);
    else rec(ret[2], lv / 3);
}

int main() {
    scanf("%s", str);
    scanf("%d %d", &n, &m);
    vector<int> vec;
    for(int i = 1; i <= n; ++i) vec.emplace_back(i);
    rec(vec, 6561);
}
