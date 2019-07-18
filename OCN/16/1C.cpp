#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 105;

char re[N];
int d[N][N];
int n, m, l;

int check() {
    vector<int> vec;
    for(int i = 1; i < n; ++i) vec.emplace_back(i);
    set<long> S;
    do {
        long sum = d[vec[0]][n] + d[vec.back()][n];
        for(int i = 1; i < vec.size(); ++i) sum += d[vec[i]][vec[i-1]];
        S.emplace(sum);
    } while(next_permutation(vec.begin(), vec.end()));
    return S.size();
}

int main() {
    srand(time(NULL));
    scanf("%s", re);
    scanf("%d %d %d", &n, &m, &l);
    int z = 10;
    double lll = l;
    int divi = l / z;
    l += l;
    int delta = 0;
    int zz = 0;
    int k = 1;
    long mx = 0;
    int ll = 56250;
    while(true) {
        delta++;
        // if(delta == 10) delta = 0, l += divi, cerr << "next" << endl;
        if(delta % 100 == 0) cerr << "next" << endl, l += divi;
        for(int i = 1; i <= n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                d[i][j] = d[j][i] = (rand() % ll) + 1;
            }
        }
                // cerr << "->" << S.size() << endl;
        int v = check();
        mx = max(mx, (long)v);
        if(delta % 10 == 0) cerr << "max => " << mx << endl;
        if(v >= m) {
            cerr << "========== YES ===========" << endl;
            int mx = 0;
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    printf("%d ", d[i][j]);
                    mx = max(mx, d[i][j]);
                }
                printf("\n");
            }
            cerr << "score : " << ((lll / mx) * 25) << endl;
            break;
        }
    }
    
}