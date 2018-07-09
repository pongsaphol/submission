#include <bits/stdc++.h>
using namespace std;

int n, p, q;

map<string, string> M;
map<string, set<string> > KK;
set<string> S;

int main() {
	int cnt = 0;
	M["Delta"] = "Eternal_City_Mac_Anu", M["Omega"] = "Warring_City_Lumina_Cloth";
	M["Theta"] = "Celestial_City_Dol_Dona", M["Sigma"] = "Dual_City_Breg_Epona";
	cin >> n >> p >> q;
	while(n--) {
		string a, b;	
		cin >> a >> b;
		S.emplace(a);
		if(M[a] != b) KK[a].emplace(b);
	}
	long sum = 0;
	sum += (S.size() - 1) * p;
	for(auto &x : KK) cnt += x.second.size();
	sum += 2ll * cnt * q;
	cout << sum << endl;
}