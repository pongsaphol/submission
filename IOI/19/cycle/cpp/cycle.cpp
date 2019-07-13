#include <bits/stdc++.h>
#include "cycle.h"
using namespace std;

void escape(int n) {
	int vb = (n-1) / 2;
	int vv = (n+1) / 2;
	if(!jump(vv)) jump(n - vv);
	int tod = 0;
	for(int i = log2(vb); i >= 0; --i) {
		if(!jump(((1<<i) + tod) % n)) tod = n - (1 << i); 
		else tod = 0;
	}
	if(tod) jump(n-1);
}
