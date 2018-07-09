#include <bits/stdc++.h>
using namespace std;

struct item {
	int val, num, prio, mx;
	item *l, *r;
	item(int val, int num) : val(val), num(num), prio(rand()), mx(num), l(NULL), r(NULL) { }
};

using pitem = item*;
int cnt(pitem t) { return t ? t->num : 0; }
void upd(pitem t) { if(t) t->mx = max({cnt(t->l), cnt(t->r), num}); }

void split(pitem &t)

int main() {

}