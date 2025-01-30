#include <stdio.h>

typedef unsigned long long ll;

ll ary[1000005];

int main() {
    ll n, b, c;
    scanf("%lld%lld%lld", &n, &b, &c);

    for (ll i = 0; i < n; i++) {
        scanf("%lld", &ary[i]);
    }

    // ==>
    ll cost = 0;

    ll cost3[3] = {2*b+c, b+2*c, 3*b};

    // 3.
    for (ll i = 0; i <= n-3; i++) {
        if (i < n-3 && ary[i+1] > ary[i+2]) {
            ll gap = ary[i+1]-ary[i+2];

            if (gap > ary[i]) {
                gap = ary[i];
            }

            ary[i]-=gap;
            ary[i+1]-=gap;
            if (2*b < b+c) {
                cost += gap*b*2;
            }
            else {
                cost += gap*(b+c);
            }
        }

        ll min = ary[i];
        for (ll j = i; j < i+3; j++) {
            if (min > ary[j]) min = ary[j];
        }

        if (min == 0) continue;
    
        for (ll j = i; j < i+3; j++) {
            // printf("3-1==%d\n", ary[j]);
            ary[j] -= min;
        }

        ll mincost = cost3[0];

        for (ll j = 1; j < 3; j++) {
            if (mincost > cost3[j]) mincost = cost3[j];
        }

        cost += min*mincost;
    }

    //2
    for (ll i = 0; i <= n-2; i++) {
        ll min = ary[i];
        for (ll j = i; j < i+2; j++) {
            if (min > ary[j]) min = ary[j];
        }

        if (min == 0) continue;
    
        for (ll j = i; j < i+2; j++) {
            // printf("2==%d\n", ary[j]);
            ary[j] -= min;
        }

        if (2*b < b+c) {
            cost += min*b*2;
        }
        else {
            cost += min*(b+c);
        }
    }

    //1
    for (ll i = 0; i < n; i++) {
        // printf("1==%d\n", ary[i]);
        cost += ary[i]*b;
    }

    printf("%lld", cost);
}