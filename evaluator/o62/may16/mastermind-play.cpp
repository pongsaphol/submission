#include "mastermind-lib.h"
#include <bits/stdc++.h>
using namespace std;

int n, k, u;

string str;
bool st = false;
bool ishave[20];

void rec(int lv) {
	if(lv == n) {
		if(st) return;
		int a, b;
		guess(str, a, b);
		if(a == n) st = true;
		return;
	}
	if(u == 0) {
		for(int i = 1; i <= k; ++i) {
			str[lv] = i+'0';
			rec(lv+1);
			if(st) return;
		}
	} else {
		for(int i = 1; i <= k; ++i) if(!ishave[i]) {
			str[lv] = i+'0';
			ishave[i] = true;
			rec(lv+1);
			ishave[i] = false;
			if(st) return;
		}
	}
	
}

void find_answer(int N, int K, int U)
{
	u = U;
	st = false;
	str = "";
	n = N, k = K;
	for(int i = 0; i < N; ++i) str.push_back('1');
	rec(0);
	// Complete this function

	// Guessing function format:
	// void guess(string g, int& num_matched, int& num_misplaced)

	// Call this function as few times as possible.
	// The answer is correct when num_matches == N.
	// When an error occurs, both returned ref values will be -1.
	// After guessing correctly, return from this function and do not
	// guess any further.

	// To compile:
	// g++ --std=c++11 mastermind-play.cpp mastermind-lib.cpp -o mastermind
	// To run:
	// ./mastermind < input_file
}
