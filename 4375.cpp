#include <stdio.h>

typedef long long ll;

int n;

int main() {
    while (scanf("%d", &n) == 2) {
        ll result = 1;

        while (result%n != 0) {
            result *= 10;
            result += 1;
        }

        printf("%d\n", result);
    }
}