#include <bits/stdc++.h>
#pragma once
using namespace std;

const int N = 1e5+5;

int n, freq[26];
char A[N];

int chk() {
	int sum = 0;
	for(int i = 0; i < 26; ++i) if(freq[i]) sum |= (1 << i);
	return sum;
}

int main() {
	scanf("%s", A);
	for(; A[n]; ++n) A[n] -= 'a';
	int l = 1, r = n;
	while(l < r) {
		memset(freq, 0, sizeof freq);
		int m = (l + r) >> 1;
		int bit = (1 << 26) - 1;
		for(int i = 0; i < m; ++i) freq[A[i]]++;
		bit &= chk();
		for(int i = m; i < n; ++i) freq[A[i-m]]--, freq[A[i]]++, bit &= chk();
		if(bit) r = m;
		else l = m + 1; 
	}
	printf("%d\n", r);
}