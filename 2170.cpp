#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct {
    ll s, e;
} line;

line ary[1000005];

int s, e;
int result;

int n;

bool cmp(line a, line b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.e < b.e;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &ary[i].s, &ary[i].e);
    }

    sort(ary, ary+n, cmp);

    s = ary[0].s;
    e = ary[0].e;
    for (int i = 1; i < n; i++) {
        line now = ary[i];

        if (now.s > e) {
            result += e - s;
            s = now.s;
            e = now.e;
            continue;
        }

        if (now.e > e) e = now.e;
    }

    result += e - s;

    printf("%d", result);
}