#include "robots.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int INF = 1e6+1;
const int INF2 = 2e9+1;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    sort(X, X + A), sort(Y, Y + B);
    int l = 1, r = 1e6+1;
    while(l < r) {
        int m = l + r >> 1;
        vector<pii> V;
        for(int i = 0; i < T; ++i) V.emplace_back(W[i], S[i]);
        sort(V.begin(), V.end());
        for(int i = 0; i < A; ++i) {
            int z = m;
            while(z) {
                bool st = true;
                for(int j = V.size() - 1; ~j; --j) {
                    if(V[j].x < X[i]) {
                        V.erase(V.begin() + j);
                        st = false;
                        z--;
                        break;
                    }
                }
                if(st) break;
            }
        }
        sort(V.begin(), V.end(), [&](const pii &a, const pii &b) { return a.y < b.y; });
        for(int i = 0; i < B; ++i) {
            int z = m;
            while(z) {
                bool st = true;
                for(int j = V.size() - 1; ~j; --j) {
                    if(V[j].y < Y[i]) {
                        V.erase(V.begin() + j);
                        st = false;
                        z--;
                        break;
                    }
                }
                if(st) break;
            }
        } 
        if(V.empty()) r = m;
        else l = m+1;
    }
    int mn = r;
    l = 1, r = INF;
    while(l < r) {
        int m = l + r >> 1;
        vector<pii> V;
        for(int i = 0; i < T; ++i) V.emplace_back(W[i], S[i]);
        sort(V.begin(), V.end(), [&](const pii &a, const pii &b) {
            if(a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        });
        for(int i = 0; i < B; ++i) {
            int z = m;
            while(z) {
                bool st = true;
                for(int j = V.size() - 1; ~j; --j) {
                    if(V[j].y < Y[i]) {
                        V.erase(V.begin() + j);
                        st = false;
                        z--;
                        break;
                    }
                }
                if(st) break;
            }
        } 
        sort(V.begin(), V.end());
        for(int i = 0; i < A; ++i) {
            int z = m;
            while(z) {
                bool st = true;
                for(int j = V.size() - 1; ~j; --j) {
                    if(V[j].x < X[i]) {
                        V.erase(V.begin() + j);
                        st = false;
                        z--;
                        break;
                    }
                }
                if(st) break;
            }
        }
        if(V.empty()) r = m;
        else l = m+1;
    }
    r = min(r, mn);
    if(r == INF) return -1;
    return r;
}
