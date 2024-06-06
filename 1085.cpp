#include <stdio.h>

int main() {
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);

    int ary[4] = {x, y, w-x, h-y};
    int min = 9999;

    for (int i = 0; i < 4; i++) {
        if (ary[i] < min) min = ary[i];
    }

    printf("%d", min);
}