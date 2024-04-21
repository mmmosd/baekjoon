#include <stdio.h>

int ary[100005];

int n, m;

int main() {
    scanf("%d%d", &n, &m);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        scanf("%d", &t);

        sum += t;
        ary[i] = sum;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%d\n", ary[b] - ary[a-1]);
    }
}