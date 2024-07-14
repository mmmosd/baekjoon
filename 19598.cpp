#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int s, e;
} c;

c ary[100005];

int n;

bool cmp(c a, c b) {
    if (a.s !=  b.s) return a.s < b.s;
    else return a.e < b.e;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ary[i].s, &ary[i].e);
    }

    sort(ary, ary+n, cmp);

    int start = -1, end = -1, result = 0;
    for (int i = 0; i < n; i++) {
        if (start == -1 && end == -1) {
            result++;
            start = ary[i].s;
            end = ary[i].e;

            continue;
        }

        if (ary[i].s < end) {
            result++;
            start = ary[i].s;
            end = ary[i].e;

            continue;
        }

        if (ary[i].s > end) end = ary[i].e;
    }

    printf("%d", result);
}