#include <bits/stdc++.h>
#define long long long
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

P mulh = P(51, 37), dubh = P(0, 0), del = P(1, 1);;
int n, len;
char in[MAXN];
string *head[MAXN], *tail[MAXN];
long cntans[MAXN];

P add(P a, P b) { return P(a.x + b.x, a.y + b.y); }
P mul(P a, P b) { return P(a.x * b.x, a.y * b.y); }

long matching(string now) {
	long cnt = 0;
	P nh = P(0, 0);
	for(int j = 0; j < len; ++j) 
		nh = add(mul(nh, mulh), P(now[j], now[j]));
	if(nh == dubh) cnt++;
	for(int j = len; j < now.size(); ++j) {
		nh = add(mul(nh, mulh), add(P(now[j], now[j]), mul(P(now[j-len], now[j-len]), del)));
		if(nh == dubh) cnt++;
	}
	return cnt;
}

map<pair<string*, string*>, long> M;

long process(string *a, string *b) {
	if(M.find(make_pair(a, b)) != M.end()) return M[make_pair(a, b)];
	string now;
	for(int i = (*a).size() - len + 1; i < (*a).size(); ++i) now.push_back((*a)[i]);
	for(int i = 0; i < len - 1; ++i) now.push_back((*b)[i]);
	return M[make_pair(a, b)] = matching(now);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%s", in);
	head[0] = tail[0] = new string("\1"), head[1] = tail[1] = new string("\2");
	do {
		in[len] -= '0' - 1;
		dubh = add(mul(dubh, mulh), P(in[len], in[len])); 
		del = mul(del, mulh);
	} while(in[++len]);
	del = P(-del.x, -del.y);
	if(len == 1) if(in[0] == 2) cntans[1] = 1; else cntans[0] = 1;
	for(int i = 2; i <= n; ++i) {
		if(i <= 27) {
			head[i] = tail[i] = new string(*head[i-1] + *head[i-2]);
			if((*head[i]).size() >= len) cntans[i] = matching(*head[i]);
			continue;
		}
		head[i] = head[i-1], tail[i] = tail[i-2];
		cntans[i] = cntans[i-1] + cntans[i-2] + process(tail[i-1], head[i-2]);
	}
	printf("%lld\n", cntans[n]);
}