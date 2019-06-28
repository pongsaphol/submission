#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e3+5;

int n, m, w, h, x, y;
int arr[N][N], qs[N][N];
pii cost[N][N];

int get(pii z) {
    return qs[z.x][z.y] - qs[z.x + x][z.y] - qs[z.x][z.y + y] + qs[z.x + x][z.y + y];
}

int main() {
    scanf("%d %d %d %d %d %d", &m, &n, &h, &w, &y, &x);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) 
        scanf("%d", &arr[i][j]);
    for(int i = n; i; --i) for(int j = m; j; --j) 
        qs[i][j] = arr[i][j] + qs[i+1][j] + qs[i][j+1] - qs[i+1][j+1];
    int szr = w-x-1; 
    int szc = h-y-1;
    for(int j = 1; j + y - 1 <= m; ++j) {
        deque<pii> Q;
        for(int i = 1; i < szr; ++i) {
            while(!Q.empty() && get(Q.back()) >= get(pii(i, j))) Q.pop_back();
            Q.push_back(pii(i, j));
        }
        for(int i = 1; i + x - 1 <= n; ++i) {
            if(i+szr-1 <= n) {
                while(!Q.empty() && get(Q.back()) >= get(pii(i+szr-1, j))) Q.pop_back();
                Q.push_back(pii(i+szr-1, j));
            }
            cost[i-1][j-1] = Q.front();
            if(Q.front().x == i) Q.pop_front();
        }
    }
    int ans = 0;
    int a1, a2, a3, a4;
    for(int i = 1; i + w - 1 <= n; ++i) {
        deque<pii> Q;
        for(int j = 1; j < szc; ++j) {
            while(!Q.empty() && get(Q.back()) >= get(cost[i][j])) Q.pop_back();
            Q.push_back(cost[i][j]);
        }
        for(int j = 1; j + h - 1 <= m; ++j) {
            while(!Q.empty() && get(Q.back()) >= get(cost[i][j+szc-1])) Q.pop_back();
            Q.push_back(cost[i][j+szc-1]);
            int val = qs[i][j] - qs[i+w][j] - qs[i][j+h] + qs[i+w][j+h] - get(Q.front());
            if(val > ans) ans = val, a1 = j, a2 = i, a3 = Q.front().y, a4 = Q.front().x;
            if(Q.front().y == j+1) Q.pop_front();
        }
    }
    printf("%d %d\n%d %d\n", a1, a2, a3, a4);
}