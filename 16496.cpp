#include <stdio.h>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

ll ary[1005];

bool cmp(ll a, ll b) {
    ll tempa = a, tempb = b;
    ll ra = a, rb = b;
    ll alen = 0, blen = 0;

    while (tempa > 0) {
        alen++;
        tempa/=10;
    }

    while (tempb > 0) {
        blen++;
        tempb/=10;
    }

    tempa = a;
    tempb = b;

    for (ll i = 0; i < blen; i++) {
        tempa *= 10;
    }

    for (ll i = 0; i < alen; i++) {
        tempb *= 10;
    }

    ra += tempb;
    rb += tempa;

    if (ra == rb) return a > b;

    return ra < rb;
}

int main() {
    ll n;
    scanf("%lld", &n);

    ll zcnt =0;
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &ary[i]);
        if (ary[i] == 0) zcnt++;
    }

    if (zcnt == n) {
        printf("0");
        return 0;
    }

    sort(ary, ary+n, cmp);

    for (ll i = 0; i < n; i++) {
        printf("%lld", ary[i]);
    }

    return 0;
}