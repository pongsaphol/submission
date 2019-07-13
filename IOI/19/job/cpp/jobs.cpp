#include <bits/stdc++.h>
#include "job.h"
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int n = 5;
long ans = 1e18;
vector<int> rr;

long scheduling_cost(vector<int> p, vector<int> u, vector<int> d) {
    vector<int> vec; for(int i = 1; i <= 2*n; ++i) vec.emplace_back(i);
    do {
        int pos[100];
        for(int i = 0; i < 2*n; ++i) pos[vec[i]] = i;
        bool st = true;
        for(int i = 1; i < n; ++i) if(pos[i] > pos[i+1] || pos[n+i] > pos[n+i+1]) st = false;
        if(!st) continue;
        long sumd = 0;
        long sumans = 0;
        for(auto x : vec) sumans += (sumd += d[x]) * u[x]; 
        if(ans > sumans) {
            rr = vec;
            ans = sumans;
        }
    } while(next_permutation(vec.begin(), vec.end()));
    FILE* f = fopen("trueans.txt", "w");
    for(auto x : rr) fprintf(f, "%d ", x);
    fprintf(f, "\n");
    fclose(f);
	return ans;
}

