/*
First, I binary search size of character A..Z, it use almost 26 * log(N) ~ 260 operation
and I connect it to right use almost (25 + ... + 1) = 325 operation
but if right side if full I will connect to left and have more 25 operatorn to ask
for subtask 3 will not use binary search find size (because all character is size 1)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1050;

int n, m;
char ans0[] = "BAASSDDFFF", ans1[] = "BBBCAAAAAA", rr[] = "";
char subtask[N], input[N];
vector<char> ent;

void answer(char *c) {
    printf("JAWAB %s\n", c);
    fflush(stdout);
    exit(0);
}

bool ask(char *c) {
    printf("TANYA %s\n", c);
    fflush(stdout);
    scanf("%s", input);
    return input[0] == 'Y';
}

char str[N];
char* arr[26];

char* add(char* a, char* b) {
    char* now = new char[N];
    sprintf(now, "%s%s", a, b);
    return now;
}

char* getp(int c, int n) {
    char* now = new char[n+5];
    for(int i = 0; i < n; ++i) now[i] = c + 'A';
    return now;
}

int main() {
    scanf("%s", subtask);
    if(subtask[0] == '0') answer(ans0);
    if(subtask[1] == '1') answer(ans1);
    scanf("%d %d", &n, &m);    
    if(subtask[3] != '3') {
        for(int i = 0; i < 26; ++i) {
            int l = 0, r = n;
            while(l < r) {
                int m = (l + r + 1) >> 1;
                if(ask(getp(i, m))) l = m;
                else r = m-1;
            }
            arr[i] = getp(i, l);
            n -= l;
        }
    } else for(int i = 0; i < 26; ++i) arr[i] = getp(i, 1);
    char *ans;
    for(int i = 0; i < 26; ++i) if(arr[i][0] != '\0') {
        ans = add(arr[i], rr);
        arr[i][0] = '\0';
        break;
    }
    while(true) {
        bool st = true;
        for(int i = 0; i < 26; ++i) if(arr[i][0] != '\0') {
            char* now = add(ans, arr[i]);
            if(ask(now)) ans = now, arr[i][0] = '\0', st = false;
        }
        if(st) break;
    }
    while(true) {
        bool st = true;
        for(int i = 0; i < 26; ++i) if(arr[i][0] != '\0') {
            char* now = add(arr[i], ans);
            if(ask(now)) ans = now, arr[i][0] = '\0', st = false;
        }
        if(st) break;
    }
    answer(ans);
}
