#include <stdio.h>

int tree[8000005];

int t;

void update(int now, int left, int right, int idx, int diff) {
	if (idx < left || idx > right) return;

	if (left == right) {
		tree[now] += diff;
	}

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

		tree[now] = tree[now*2] + tree[now*2+1];
	}
}

int q(int now, int left, int right, int x) {
    if (left == right) return left;

	if (left < right) {
		int mid = (left+right)/2;
		int a = tree[now*2];

        if (a < x) return q(now*2+1, mid+1, right, x-a);
        else return q(now*2, left, mid, x);
	}
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int t, x;
        scanf("%d%d", &t, &x);

        if (t == 1) {
            update(1, 1, 2000000, x, 1);
        }
        else {
            int r = q(1, 1, 2000000, x);
            printf("%d\n", r);
            update(1, 1, 2000000, r, -1);
        }
    }
}