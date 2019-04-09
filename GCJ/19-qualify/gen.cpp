#include <bits/stdc++.h>
using namespace std;

bool pick[10010];

int main(int argc, char *argv[])
{
    vector<int> P;
    for (int i = 2; i <= 10000; ++i) {
        if (!pick[i]) P.push_back(i);
        for (int j = i+i; j <= 10000; j += i)
            pick[j] = true;
    }

    mt19937 rnd(atoi(argv[1]));
    uniform_int_distribution<int> dis(0, P.size()-1);
    set<int> sel;
    while (sel.size() < 26) {
        int i = dis(rnd);
        sel.insert(P[i]);
    }
    vector<int> LP(sel.begin(), sel.end());

    uniform_int_distribution<int> dis2(0, 25);
	string s;
	cin >> s;
    printf("1\n10000 %d\n", s.size()-1);
    for (int i = 0; i < s.size()-1; ++i) {
        if (i != 0) printf(" ");
        printf("%d", LP[s[i]-'A']*LP[s[i+1]-'A']);
        fprintf(stderr, "%d %d %c%c\n", LP[s[i]-'A'], LP[s[i+1]-'A'], s[i], s[i+1]);
    }
    printf("\n");

    for (auto x : LP)
        fprintf(stderr, "%d ", x);
    fprintf(stderr, "\n%s\n", s.c_str());
	for(int i = 0; i < 26; ++i) fprintf(stderr, "%c %d\n", i + 'A', LP[i]);    
    return 0;
}
