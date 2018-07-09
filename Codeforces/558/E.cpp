#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<17;

int n, m, lz[MAXN<<1];
char A[MAXN];

struct data {
	int A[27] = {};
	friend inline data operator+(const data &a, const data &b) {
		data ret;
		for(int i = 1; i <= 26; ++i) ret.A[i] = a.A[i] + b.A[i];
		return ret;
	}
	void clear() {
		for(int i = 1; i <= 26; ++i) A[i] = 0;
	}
};

data t[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p].A[A[l]-'a'+1]++;
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p].clear();
		t[p].A[lz[p]] = r-l+1;
		if(l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int x, int y, int v) {
	data ret;
	travel(x, y, [&](int p, int l, int r) {
		ret = ret + t[p];
	});
	if(!v) {
		int ptr = x;
		for(int i = 26; i != 0; --i) if(ret.A[i]) {
			travel(ptr, ptr + ret.A[i] - 1, [&](int p, int l, int r) {
				t[p].clear();
				t[p].A[i] += r-l+1;
				if(l != r) lz[p<<1] = lz[p<<1|1] = i;
			});
			ptr += ret.A[i];
		}
	} else {
		int ptr = x;
		for(int i = 1; i <= 26; ++i) if(ret.A[i]) {
			travel(ptr, ptr + ret.A[i] - 1, [&](int p, int l, int r) {
				t[p].clear();
				t[p].A[i] += r-l+1;
				if(l != r) lz[p<<1] = lz[p<<1|1] = i;
			});
			ptr += ret.A[i];
		}
	}
}

void print() {
	for(int i = 1; i <= n; ++i) {
		data ret;
		travel(i, i, [&](int p, int l, int r) {
			ret = t[p];
		});
		for(int j = 1; j <= 26; ++j) if(ret.A[j]) printf("%c", j+'a'-1);
	}
	puts("");
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	scanf("%s", A+1);
	build();
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		update(a, b, c);
	}
	print();	
}