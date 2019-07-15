#include "paint.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, k;
int pref_[N], prefX[N];
int canX[N], can_[N];
bool state[105][N];
char arr[N];
int sz[N];

string solve_puzzle(string s, vector<int> C) {
    n = s.size(), k = C.size();
    for(int i = 0; i < n; ++i) arr[i+2] = s[i];
    for(int i = 0; i < k; ++i) sz[i+1] = C[i];
    for(int i = 2; i <= n+1; ++i) pref_[i] = pref_[i-1] + (arr[i] == '_' ? 1 : 0);
    for(int i = 2; i <= n+1; ++i) prefX[i] = prefX[i-1] + (arr[i] == 'X' ? 1 : 0);
    pref_[n+2] = pref_[n+1], prefX[n+2] = prefX[n+1];
    state[0][0] = 1;
    for(int i = 1; i <= k; ++i) {
        int lst = -1;
        for(int j = sz[i]+1; j <= n+1; ++j) {
            if(state[i-1][j-sz[i]-1]) lst = j-sz[i]-1; 
            if(lst != -1 && (prefX[j-sz[i]] - prefX[lst] == 0) && (pref_[j] - pref_[j-sz[i]] == 0)
                && (prefX[(i == k ? n : j) + 1] - prefX[j] == 0)) state[i][j] = 1;
        }
    }
    for(int i = k; i >= 0; --i) {
        if(i == k) for(int j = n+1; j >= 0; --j) {
            if(state[i][j]) {
                canX[j-sz[i]+1]++, canX[j+1]--, can_[j+1]++, can_[n+2]--;
            }
        } else {
            int l = n+1, r = n+1;
            while(true) {
                if(state[i+1][r]) {
                    if(r-l <= sz[i+1]) state[i][l--] = false;
                    else if(state[i][l]) {
                        if(prefX[r-sz[i+1]] - prefX[l] == 0) canX[l-sz[i]+1]++, canX[l+1]--, can_[l+1]++, can_[r-sz[i+1]+1]--, l--;
                        else r--;
                    } else l--;
                } else r--;
                if(l < 0 || r < 0) break;
            }
            for(int j = l; j >= 0; --j) state[i][j] = false;
        }
    }
    for(int j = 2; j <= n+1; ++j) canX[j] += canX[j-1], can_[j] += can_[j-1];
    string str;
    for(int j = 2; j <= n+1; ++j) {
        if(canX[j] && can_[j]) str.push_back('?');
        else if(canX[j]) str.push_back('X');
        else str.push_back('_');
    }
    return str;
}
