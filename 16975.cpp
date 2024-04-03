#include <stdio.h>

typedef long long ll;

ll ary[100005];

ll tree[400005];

int n, m;

void update(int now, int left, int right, int start, int end, ll diff) {
    if (end < left || right < start) return;
    if (left == right) {
        tree[now] += diff;
        return; 
    }

    if (left < right) {
        int mid = (left + right) / 2;

        update(now*2, left, mid, start, end, diff);
        update(now*2+1, mid+1, right, start, end, diff);

        tree[now] += tree[now*2] + tree[now*2+1];
    }
}

ll find(int now, int left, int right, int idx) {
    if (left > idx || right < idx) return 0;
    if (left == right && left == idx) return tree[now];

    if (left < right) {
        int mid = (left + right) / 2;

        ll a = find(now*2, left, mid, idx);
        ll b = find(now*2+1, mid+1, right, idx);

        return a+b;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);

        ary[i] = t;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);

        if (q == 1) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);

            update(1, 1, n, a, b, c);
        }
        else {
            int a;
            scanf("%d", &a);

            printf("%lld\n", ary[a] + find(1, 1, n, a));
        }
    }
}