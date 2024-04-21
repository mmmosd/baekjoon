#include <stdio.h>

int ary[1000005] = {0, 1};

int n;

int main() {
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        ary[i] = (ary[i-1]%1000000007 + ary[i-2]%1000000007)%1000000007;
    }

    printf("%d", ary[n]);
}