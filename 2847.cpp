#include <stdio.h>

int ary[105];
int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    int result = 0;
    for (int i = n-1; i >= 1; i--) {
        int now = ary[i], before = ary[i-1]; //now > before

        while (before >= now) {
            result++;
            before--;
        }

        ary[i-1] = before;
    }

    printf("%d", result);
}