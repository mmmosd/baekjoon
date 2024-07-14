#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int s, e, c;
} route;

route ary[200005];

int n;

bool cmp(route a, route b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.e < b.e;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &ary[i].s, &ary[i].e, &ary[i].c);
    }

    sort(ary, ary+n, cmp);

    vector<route> result;

    int start = -1, end = -1, cost = -1;
    for (int i = 0; i < n; i++) {
        if (start == -1 && end == -1) {
            start = ary[i].s;
            end = ary[i].e;
            cost = ary[i].c;

            continue;
        }

        if (ary[i].s > end) {
            result.push_back({start, end, cost});
            start = ary[i].s;
            end = ary[i].e;
            cost = ary[i].c;

            continue;
        }

        if (ary[i].c < cost) cost = ary[i].c;

        if (ary[i].e > end) {
            end = ary[i].e;
        }
    }
    result.push_back({start, end, cost});

    int count = result.size();
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", result[i].s, result[i].e, result[i].c);
    }
}