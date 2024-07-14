#include <stdio.h>

typedef long long ll;

ll segment[4000005];

void update(int now, int left, int right, int idx, ll diff) {
	if (idx < left || idx > right) return;

	if (left == right) {
		segment[now] = diff;
	}

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

		segment[now] = segment[now*2] + segment[now*2+1];
	}
}

ll sum(int now, int left, int right, int start, int end) {
	if (left > end || right < start) return 0;
	if (start <= left && right <= end) return segment[now];

	if (left < right) {
		int mid = (left+right)/2;
		ll a = sum(now*2, left, mid, start, end);
		ll b = sum(now*2+1, mid+1, right, start, end);

		return a+b;
	}
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);

        update(1, 1, n, i+1, in);
    }

    for (int i = 0; i < q; i++) {
        ll x, y, a, b;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);

        if (x > y) printf("%lld\n", sum(1, 1, n, y, x));
        else printf("%lld\n", sum(1, 1, n, x, y));
        update(1, 1, n, a, b);
    }
}