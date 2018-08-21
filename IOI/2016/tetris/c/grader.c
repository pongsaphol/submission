#include "tetris_c.h"

#include <stdio.h>
#include <stdlib.h>

int a[1000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    	scanf("%d", &a[i]);

    init(n);
    for (int i = 0; i < n; i++) {
    	new_figure(a[i]);
        printf("%d %d\n", get_position(), get_rotation());
    }

    return 0;
}
