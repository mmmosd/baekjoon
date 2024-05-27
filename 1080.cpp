#include <stdio.h>

int map1[55][55], map2[55][55];

int n, m;

int main() {
    scanf("%d%d", &n, &m);

    int result = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map2[i][j]);

            map2[i][j] += map1[i][j];

            if (map2[i][j] == 2) {
                result++;
            }
        }
    }

    printf("%d", result);
}