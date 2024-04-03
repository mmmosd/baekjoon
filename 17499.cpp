#include <stdio.h>

int ary[200005];

int n, m;

int main() {
    scanf("%d%d", &n, &m);

    int cur = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ary[i]);
    }

    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);

        if (q == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
        }
        else if (q == 2) {
            int a;
            scanf("%d", &a);

            for (int j = 1; j <= a; j++) {
                ary[n+j] = ary[cur++];
            }
        }
        else {
            int a;
            scanf("%d", &a);

            for (int j = 1; j <= a; j++) {
                ary[] = ary[];
            }
        }

        printf("==%d\n", cur);
    }
}