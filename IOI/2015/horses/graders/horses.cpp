#include "horses.h"
#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1<<19, M = 1e9+7;

int n, X[N], Y[N];
double t[N<<1], lz[N<<1];
long val[N<<1], lzval[N<<1];

long powMod(long a, long b) {
	long ret = 1;
	while(b) {
		if(b & 1) ret = (ret * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return ret;
}

int invMod(long v) {
	return (int)powMod(v, M-2);
}

void update(int p) {
	if(t[p<<1] > t[p<<1|1]) val[p] = val[p<<1], t[p] = t[p<<1];
	else val[p] = val[p<<1|1], t[p] = t[p<<1|1];
}

void push(int p, int l, int r) {
	if(lzval[p] != 1 || lz[p] != 0.0) {
		val[p] = (val[p] * lzval[p]) % M;
		t[p] += lz[p];
		if(l != r) {
			lzval[p<<1] = (lzval[p<<1] * lzval[p]) % M;
			lzval[p<<1|1] = (lzval[p<<1|1] * lzval[p]) % M;
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
	}	
	lzval[p] = 1, lz[p] = 0.0;
}

void build(int p = 1, int l = 0, int r = n-1) {
	if(l == r) {
		t[p] = log2(Y[l]), val[p] = Y[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	update(p);
}

void modify(int x, int y, int a, double b, int p = 1, int l = 0, int r = n-1) {
	push(p, l, r);
	if(x > r || l > y) return;
	if(x <= l && r <= y) {
		lz[p] += b, lzval[p] = (lzval[p] * a) % M, push(p, l, r);
		return;
	}
	int m = (l + r) >> 1;
	modify(x, y, a, b, p<<1, l, m), modify(x, y, a, b, p<<1|1, m+1, r);
	update(p);	
}

int init(int z, int x[], int y[]) {
	n = z;
	for(int i = 0; i < n; ++i) X[i] = x[i], Y[i] = y[i];
	fill(lzval, lzval + (::N<<1), 1);
	build();
	for(int i = 0; i < n; ++i) modify(i, n-1, X[i], log2(X[i]));
	return (int)val[1];
}

int updateX(int pos, int v) {	
	modify(pos, n-1, invMod(X[pos]), -log2(X[pos]));
	modify(pos, n-1, X[pos] = v, log2(v));
	return (int)val[1];
}

int updateY(int pos, int v) {
	modify(pos, pos, invMod(Y[pos]), -log2(Y[pos]));
	modify(pos, pos, Y[pos] = v, log2(v));
	return (int)val[1];
}
