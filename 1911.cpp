#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int s, e;
} pd;

pd ary[10005];

int n, l;

bool cmp(pd a, pd b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.e < b.e;
}

int main() {
    scanf("%d%d", &n, &l);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ary[i].s, &ary[i].e);
    }

    sort(ary, ary+n, cmp);

    int start = -1, end = -1, result = 0;
    for (int i = 0; i < n; i++) {
        if (start == -1 && end == -1) {
            start = ary[i].s;
            end = ary[i].s;
        }

        if (end < ary[i].s) {
            start = ary[i].s;
            end = ary[i].s;
        }

        while (end < ary[i].e) {
            end += l;
            result++;
        }
    }

    printf("%d", result);
}