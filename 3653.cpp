#include <stdio.h>

typedef long long ll;

ll tree[400005];

int t;

void update(int now, int left, int right, int idx, ll diff) {
    if (idx < left || right < idx) return;

    if (left == right) {
        tree[now] += diff;
    }

    if (left < right) {
        int mid = (left+right) / 2;

        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        tree[now] = tree[now*2] + tree[now*2+1];
    }
}

ll sum(int now, int left, int right, int start, int end) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[now];

    if (left < right) {
        int mid = (left + right) / 2;

        ll a = sum(now*2, left, mid, start, end);
        ll b = sum(now*2+1, mid+1, right, start, end);

        return a + b;
    }
}

int main() {
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++) {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            update(1, 1, n, i, 1);
        }

        int topidx = 1;
        for (int i = 0; i < m; i++) {
            int in;
            scanf("%d", &in);

            printf("%lld ", in + sum(1, 1, n, in+1, n));

            update(1, 1, n, in, 0);
            update(1, 1, n, topidx, 1);
            topidx = in;
        }

        printf("\n");
    }
}