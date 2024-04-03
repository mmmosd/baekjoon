#include <stdio.h>

int n;

int find(int x) {
    if (x < n) {
        return find(x+1) + find(x+1);
    }
    else return x;
}

int main() {
    scanf("%d", &n);

    int result = 2;
    printf("%d\n", find(n));
}