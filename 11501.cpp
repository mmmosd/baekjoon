#include <stdio.h>

int ary[1000005];

int t;

int main() {
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ary[i]);
        }
    }
}