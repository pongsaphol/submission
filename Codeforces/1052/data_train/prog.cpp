#include <bits/stdc++.h>
using namespace std;

#define long long long

char file[1000][20];

int main() {
    freopen("file.txt", "r", stdin);
    int p = 0;
    while(scanf("%s", file[p++]) != EOF) {}
    double avg1 = 0, avg2 = 0;
    for(int i = 0; i < p; ++i) {
        freopen(file[i], "r", stdin);
        int n, m; scanf("%d,%d", &n, &m);
        printf("%d %d\n", n, m);
        double suma = 0, sumb = 0;
        int cnt = 0;
        int r1, r2;
        while(scanf("%d,%d", &r1, &r2) != EOF) {
            cnt++;
            suma += r1, sumb += r2;
        } 
        printf("%d\n", cnt);
        suma /= cnt, sumb /= cnt;
        avg1 += suma / n, avg2 += sumb / m;
        
    }
    avg1 /= p, avg2 /= p;
    printf("%.6f, %.6f", avg1, avg2);
} 
