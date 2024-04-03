#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
    int min, max;
} node;

node tree[400005];

int tc;

void init(int now, int left, int right) {
    if (left == right) tree[now] = {left, left};

    if (left < right) {
        int mid = (left + right) / 2;

        init(now*2, left, mid);
        init(now*2+1, mid+1, right);

        tree[now].min = tree[now*2].min < tree[now*2+1].min ? tree[now*2].min : tree[now*2+1].min;
        tree[now].max = tree[now*2].max > tree[now*2+1].max ? tree[now*2].max : tree[now*2+1].max;
    }
}

void update(int now, int left, int right, int idx, int diff) {
    if (left > idx || idx > right) return;
    if (left == right) tree[now] = {diff, diff};

    if (left < right) {
        int mid = (left + right) / 2;

        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        tree[now].min = tree[now*2].min < tree[now*2+1].min ? tree[now*2].min : tree[now*2+1].min;
        tree[now].max = tree[now*2].max > tree[now*2+1].max ? tree[now*2].max : tree[now*2+1].max;
    }
}

node find(int now, int left, int right, int start, int end) {
    if (start <= left && right <= end) return tree[now];
    if (right < start || left > end) return {-1, -1};

    if (left < right) {
        int mid = (left + right) / 2;

        node a = find(now*2, left, mid, start, end);
        node b = find(now*2+1, mid+1, right, start, end);
        node t;

        t.min = a.min < b.min ? a.min : b.min;
        t.max = a.max > b.max ? a.max : b.max;

        if (a.min == -1 && a.max == -1) t = b;
        if (b.min == -1 && b.max == -1) t = a;

        return t;
    }
}

int main() {
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        int n, k;
        scanf("%d%d", &n, &k);
        init(1, 0, n-1);

        for (int i = 0; i < k; i++) {
            int q, a, b;
            scanf("%d%d%d", &q, &a, &b);

            if (q == 0) {
                node a1 = find(1, 0, n-1, a, a), b1 = find(1, 0, n-1, b, b);

                update(1, 0, n-1, a, b1.min);
                update(1, 0, n-1, b, a1.min);
            }
            else {
                node result = find(1, 0, n-1, a, b);

                // printf("min: %d | max: %d\n", s.min, s.max);

                if (result.min == a && result.max == b) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
}