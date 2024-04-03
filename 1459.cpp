#include <stdio.h>

typedef long long ll;

ll x, y, w, s;

int main() {
    scanf("%lld%lld%lld%lld", &x, &y, &w, &s);

    ll max = 0, min = 0;

    if (x > y) {
        max = x;
        min = y;
    }
    else {
        max = y;
        min = x;
    }

    ll r1 = max*s, r2 = min*s + (max-min)*w, r3 = w*x + w*y;

    ll ary[3] = {r1, r2, r3};
    ll result = ary[0];

    for (int i = 0; i < 3; i++) {
        if (ary[i] < result) result = ary[i];
    }

    printf("%lld", result);
}