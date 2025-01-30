#include <stdio.h>

typedef long long ll;

ll ary[100005];

int main() {
    ll n;
    scanf("%lld", &n);

    for (ll i = 0; i < n; i++) {
        scanf("%lld", &ary[i]);
    }

    // ==>
    ll cost = 0;

    // 3.
    for (ll i = 0; i <= n-3; i++) {
        while (i < n-3 && ary[i+1] > ary[i+2] && ary[i] > 0) {
            ary[i]--;
            ary[i+1]--;
            cost += 5;
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

        cost += min*7;
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

        cost += min*5;
    }

    //1
    for (ll i = 0; i < n; i++) {
        // printf("1==%d\n", ary[i]);
        cost += ary[i]*3;
    }

    printf("%lld", cost);
}