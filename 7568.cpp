#include <stdio.h>

typedef struct {
    int x, y;
} node;

node ary[55];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ary[i].x, &ary[i].y);
    }

    for (int i = 0; i < n; i++) {
        int result = 1;

        for (int j = 0; j < n; j++) {
            if (ary[i].x < ary[j].x && ary[i].y < ary[j].y) {
                result++;
            }
        }

        printf("%d ", result);
    }
}