#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int top = -1, result = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (top == -1) {top = a;result++;}
        if (a > top) {top = a;result++;}
    }

    printf("%d", result);
}