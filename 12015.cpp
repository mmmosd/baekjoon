#include <stdio.h>

typedef long long ll;

ll tree[4000005];

int n;

void update(int now, int left, int right, int idx, ll diff) {
    if (idx < left || right < idx) return;

    if (left == right) {
        tree[now] += diff;
    }

    if (left < right) {
        int mid = (left + right) / 2;

        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        if (tree[now*2] < tree[now*2+1]) {
            tree[now] = tree[now*2];
        }
        else {
            tree[now] = tree[now*2+1];
        }
    }
}

ll find(int now, int left, int right, int start, int end) {
    if (end < left || right < start) return 9999999;
    if (left <= start && end <= right) return tree[now];

    if (left < right) {
        int mid = (left + right) / 2;

        ll a = find(now*2, left, mid, start, end);
        ll b = find(now*2+1, mid+1, right, start, end);

        if (a < b) return a;
        else return b;
    }
}

int ary[1000005];
int main() {
    scanf("%d", &n);

    int max = -1;
    int min = 9999999;
    int count = 0;
    for (int i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);
        ary[in] += 1;
        if (max < in) max = in;
        if (min > in) min = in;
        
    }

    for (int i = min; i <= max; i++) {
        count += ary[i];
        if (ary[i] == 1) update(1, min, max, ary[i], 1);
    }

    printf("%d %d %d %d\n", count, min, max, find(1, min, max, min, max));

    printf("%lld", find(1, min, max, min, max)*count);
}