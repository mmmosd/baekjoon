#include <stdio.h>
#include <algorithm>
using namespace std;

int ary[1000005];
int n;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    sort(ary, ary+n, cmp);

    for (int i = 0; i < n; i++) {
        printf("%d\n", ary[i]);
    }
}