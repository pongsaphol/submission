#include <bits/stdc++.h>
#include "grader.h"
using namespace std; 

int solve(int l, int r, int pre = -1) {
   int sz = r-l+1;
   if(sz == 1) return l;
   if(sz == 2) {
      Guess(l);
      if(Guess(r) == 1) return r;
      else return l; 
   }
   if(sz == 3) {
      Guess(l);
      int val = Guess(r);
      if(val == 1) return r;
      if(val == 0) return r-1;
      return l;
   }
   int a = l + sz/3;
   int b = l + 2*sz/3;
   if(pre != -1) {
      if(abs(a - pre) <= abs(b - pre)) a = pre;
      else b = pre;
   }   
   int m = a + b >> 1;
   if(pre != -1) {
      if(a == pre) {
         int val = Guess(b);
         if(val == 0) return m;
         if(val == 1) return solve(m+1, r, b);
         else return solve(l, m, -1);
      } else {
         int val = Guess(a);
         if(val == 0) return m;
         if(val == 1) return solve(l, m, a);
         else return solve(m+1, r, -1);
      }
   } else if(rand() % 2) {
      Guess(a);
      int val = Guess(b);
      if(val == 0) return m;
      if(val == 1) return solve(m+1, r, b);
      return solve(l, m, -1);
   } else {
      Guess(b);
      int val = Guess(a);
      if(val == 0) return m;
      if(val == 1) return solve(l, m, a);
      return solve(m+1, r, -1);
   }
}

bool st;

int HC(int N){
   if(!st) srand(time(NULL)), st = true;
   return solve(1, N);
}
