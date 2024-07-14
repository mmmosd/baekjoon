#include <stdio.h>

typedef long long ll;

typedef struct {
    ll size, v; // size: number size , v: Wkrtn
} node;

node segment[4000005];

void update(int now, int left, int right, int idx, ll diff) {
	if (idx < left || idx > right) return;

	if (left == right) {
		segment[now].v = diff%2 == 0;
        segment[now].size = 1;
	}

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

		segment[now].size = segment[now*2].size + segment[now*2+1].size;
        segment[now].v = segment[now*2].v + segment[now*2+1].v;
	}
}

node find(int now, int left, int right, int start, int end) {
	if (left > end || right < start) return {0, 0};
	if (start <= left && right <= end) return segment[now];

	if (left < right) {
		int mid = (left+right)/2;
		node a = find(now*2, left, mid, start, end);
		node b = find(now*2+1, mid+1, right, start, end);

		return {a.size + b.size, a.v + b.v};
	}
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);

        update(1, 1, n, i+1, in);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
		int a;
		scanf("%d", &a);
		ll x, y;
		scanf("%lld%lld", &x, &y);

		if (a == 1) {
	        update(1, 1, n, x, y);
		}
		else if (a == 2) {
            node t = find(1, 1, n, x, y);
            printf("%lld\n", t.v);
        }
        else {
            node t = find(1, 1, n, x, y);
            printf("%lld\n", t.size - t.v);
        }
    }
}