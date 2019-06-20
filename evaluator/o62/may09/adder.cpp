#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

int n, m;

int arr[10][3] = 
{{1, 0, 1}, {2, 0, 1}, {0, -2, 0}, {1, -1, -2}, {1, -1, 2}, {2, -2, 2}, {0, -2, 0}, {1, -2, -1}, {2, -8, -4}};

char cc[3][6] = {"NOT", "AND", "OR"};

int a[3];

int main() {
    cin >> n >> m;
    vector<iii> ans;
    vector<int> ans2;
    int ptr = 1;
    for(int i = 1; i <= n; ++i) {
        a[0] = -i, a[1] = -i-n;
        for(int j = 0; j < 9; ++j) {
            int a1 = arr[j][0], a2 = arr[j][1], a3 = arr[j][2];
            if(a2 < 0) a2 += ptr;
            else a2 = a[a2];
            if(a3 < 0) a3 += ptr;
            else a3 = a[a3];
            ans.emplace_back(a1, a2, a3);
            if(j == 7) ans2.emplace_back(ptr);
            if(j == 8) a[2] = ptr;
            ptr++;
        }
    }
    ans2.emplace_back(a[2]);
    printf("%d\n", ans.size());
    for(auto x : ans2) printf("%d ", x);
    printf("\n");
    for(auto x : ans) {
        int u, v, w; tie(u, v, w) = x;
        printf("%s %d", cc[u], v);
        if(u) printf(" %d", w);
        printf("\n");
    }
}