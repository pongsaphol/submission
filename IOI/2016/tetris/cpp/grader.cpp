#include "tetris.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
    	std::cin >> a[i];

    init(n);
    for (int i = 0; i < n; i++) {
    	new_figure(a[i]);
    	std::cout << get_position() << " " << get_rotation() << std::endl;
    }

    return 0;
}
