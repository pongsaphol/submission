#include <bits/stdc++.h>
#include "sort_weight.h"
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define x first
#define y second
#define vi vector<int>
using namespace std;

int d_tree[256];
vector<pii> cmpf;
vector<vi> permut;

pii getNum(int id) {
  return cmpf[--id];
}

namespace gen_d_tree {
  bool dfs(vi vec, int p = 0, int sz = 128) {
    if(vec.size() > sz) return false;
    if(vec.size() == 1) {
      d_tree[p] = -vec[0];
      return true;
    }
    if(sz == 1) return true;
    for(int i = 1; i <= cmpf.size(); ++i) {
      pii z = getNum(i);
      vi vec1, vec2;
      for(auto x : vec) {
        if(permut[x][z.x] < permut[x][z.y]) vec1.emplace_back(x);
        else vec2.emplace_back(x);
      }
      bool s1 = dfs(vec1, p*2+1, sz >> 1);
      bool s2 = dfs(vec2, p*2+2, sz >> 1);
      if(s1 && s2) {
        d_tree[p] = i;
        return true;
      }
    }
    return false;
  }

  void main() {
    vi now(120);
    iota(all(now), 0);
    dfs(now);
  } 
}

namespace solve_problem {
  void dfs(int p = 0) {
    if(d_tree[p] <= 0) {
      vector<int> ans(5);
      for(int i = 0; i < 5; ++i) ans[permut[-d_tree[p]][i]] = i;
      sort_answer(ans[0], ans[1], ans[2], ans[3], ans[4]);
      return;
    }
    pii z = getNum(d_tree[p]);
    int val = sort_weight(z.x, z.y);
    if(val == -1) dfs(p*2+1);
    else dfs(p*2+2);
  }
  void main() {
    int testcase = get_case();
    while(testcase--) {
      sort_init();
      dfs();
    }
  }
}

void init() {
  vi now(5);
  iota(all(now), 0);
  do {
    permut.emplace_back(now);
  } while(next_permutation(all(now)));
  for(int i = 0; i < 5; ++i) for(int j = i+1; j < 5; ++j) cmpf.emplace_back(i, j);
}

int main() {
  init();
  gen_d_tree::main();
  solve_problem::main();
}
