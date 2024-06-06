#include <stdio.h>

int map[55][55];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 50; k++) {
                if (i+k >= n || j+k >= m) break;

                int p1 = map[i][j], p2 = map[i+k][j], p3 = map[i][j+k], p4 = map[i+k][j+k];

                if (p1 == p2 && p2 == p3 && p3 == p4) {
                    int now = (k+1)*(k+1);

                    if (result < now) {
                        result = now;
                    }
                }
            }
        }
    }

    printf("%d", result);
}