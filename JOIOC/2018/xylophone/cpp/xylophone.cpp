#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

static int A[5000];

void solve(int N) {
	int value = query(1, N);
	for(int i = 1; i <= N; i++) {
		answer(i, i);
	}
}
