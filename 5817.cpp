#include <stdio.h>

typedef struct {
    int min, max;
} node;

int ary[200000];
node tree[800000];

int n, m;

void update(int now, int left, int right, int idx, int diff) {
    if (idx < left || right < idx) return;

    if (left == right) tree[now] = {diff, diff};

    if (left < right) {
        int mid = (left + right) / 2;

        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        if (tree[now*2].min < tree[now*2+1].min) tree[now].min = tree[now*2].min;
        else tree[now].min = tree[now*2+1].min;

        if (tree[now*2].max > tree[now*2+1].max) tree[now].max = tree[now*2].max;
        else tree[now].max = tree[now*2+1].max;
    }
}

node query(int now, int left, int right, int start, int end) {
    if (end < left || right < start) return {200005, -1};
    if (left <= start && end <= right) return tree[now];

    if (left < right) {
        int mid = (left + right) / 2;

        node a = query(now*2, left, mid, start, end);
        node b = query(now*2+1, mid+1, right, start, end);
        node r = {-1, -1};

        if (a.min < b.min) r.min = a.min;
        else r.min = b.min;

        if (a.max > b.max) r.max = a.max;
        else r.max = b.max;

        return r;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        ary[i+1] = in;

        update(1, 1, n, i+1, in);
    }

    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            int x, y;
            scanf("%d%d", &x, &y);

            update(1, 1, n, x, ary[y]);
            update(1, 1, n, y, ary[x]);

            printf("---- == %d %d\n", ary[x], ary[y]);

            int temp = ary[x];
            ary[x] = ary[y];
            ary[y] = temp;
        }
        else {
            int x, y;
            scanf("%d%d", &x, &y);

            node q = query(1, 1, n, x, y);

            printf("== %d %d\n", q.min, q.max);

            if (q.min == x && q.max == y) printf("YES\n");
            else printf("NO\n");
        }
    }
}   