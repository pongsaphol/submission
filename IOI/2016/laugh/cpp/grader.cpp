#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "laugh.h"

int main() {
    std::string s;
    std::cin >> s;
    printf("%d\n", longest_laugh(s));
    return 0;
}
