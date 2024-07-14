#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
    int s, e;
} route;

vector<route> ary;

int n, m;

bool cmp(route a, route b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.e < b.e;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int s, e;
        scanf("%d%d", &s, &e);

        if (s > e) {
            ary.push_back({e, s});
        }
    }

    sort(ary.begin(), ary.end(), cmp);

    int start = -1, end = -1;
    ll result = m;
    int count = ary.size();

    for (int i = 0; i < count; i++) {
        if (start == -1) {
            start = ary[i].s;
            end = ary[i].e;
            continue;
        }

        if (ary[i].s > end) {
            result += (end - start)*2;

            start = ary[i].s;
            end = ary[i].e;
            continue;
        }

        if (ary[i].e > end) {
            end = ary[i].e;
        }
    }

    result += (end - start)*2;

    printf("%lld", result);
}