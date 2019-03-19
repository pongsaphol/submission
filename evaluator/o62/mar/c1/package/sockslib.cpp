#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "sockslib.h"

using namespace std;

map<int,int> socks;
int ask_count;
int ask_limits = 1000000;


int num() {
  ask_count = 0;
  int n = 3;
  vector<int> v = {1,2,3,3,1,2};
  for (int i = 0;i < 2*n;i++) { socks[i+1] = v[i]; }
  return n;
}

int ask(vector<int> &v) {
  ask_count++;
  if (ask_count > ask_limits) {
    printf("ERROR: you have called ask more than the limit of %d\n",ask_limits);
    exit(0);
  }
  set<int> s;
  for (auto &x : v) {
    s.insert(socks[x]);
  }
  return (int)s.size();
}

bool match(int a,int b) {
  if (socks[a] == socks[b]) {
    socks.erase(a);
    socks.erase(b);

    if (socks.empty()) {
      printf("COMPLETE!!!, you call 'ask' %d times\n",ask_count);
      exit(0);
    }
    return true;
  } else {
    printf("ERROR: wrong matching for %d and %d\n",a,b);
    printf("you call 'ask' \%d times\n",ask_count);
    exit(0);
  }

}


