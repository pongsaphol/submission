#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

char inp[N];
set<int> S[3][N];
char o1[N], o2[N];

int main() {
    scanf("%s", inp+1);
    int n = strlen(inp+1);
    int block = n / 26 + 1;
    for(int i = 1, p = 0; i <= n; ++i) {
        o1[i] = p + 'a';
        if(i % block == 0) p++;
    }
    printf("? %s\n", o1+1);
    fflush(stdout);
    scanf("%s", o2+1);
    vector<int> vec[26];
    for(int i = 1; i <= n; ++i) {
        vec[o2[i] - 'a'].emplace_back(i);
    }
    for(int i = 1; i <= n; ++i) for(auto x : vec[o1[i] - 'a']) S[0][i].emplace(x);
    int block2 = block / 26 + 1;
    for(int i = 1, p = 0; i <= n; ++i) {
        o1[i] = p + 'a';
        if(((i % block) % block2) == 0) p++;
        if(i % block == 0) p = 0;
    }
    printf("? %s\n", o1+1);
    fflush(stdout);
    scanf("%s", o2+1);
    vector<int> vec2[26];
    for(int i = 1; i <= n; ++i) {
        vec2[o2[i] - 'a'].emplace_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        for(auto x : vec2[o1[i] - 'a']) if(S[0][i].find(x) != S[0][i].end()) S[1][i].emplace(x);
    }
    int block3 = block2 / 26 + 1;
    for(int i = 1, p = 0; i <= n; ++i) {
        o1[i] = p + 'a';
        if(((i % block) % block2) % block3 == 0) p++;
        if(((i % block) % block2) == 0) p = 0;
    }
    printf("? %s\n", o1+1);
    fflush(stdout);
    scanf("%s", o2+1);
    vector<int> vec3[26];
    for(int i = 1; i <= n; ++i) {
        vec3[o2[i] - 'a'].emplace_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        for(auto x : vec3[o1[i] - 'a']) if(S[1][i].find(x) != S[1][i].end()) o1[i] = inp[x];
    }
    printf("! %s\n", o1+1);
    fflush(stdout);
}
