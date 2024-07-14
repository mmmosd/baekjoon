#include <stdio.h>

typedef long long ll;

int segment[4000005];

void update(int now, int left, int right, int idx, int diff) {
	if (idx < left || idx > right) return;

	if (left == right) {
        int r = 0;

        if (diff > 0) r = 1;
        else if (diff < 0) r = -1;

		segment[now] = r;
	}

	if (left < right) {
		int mid = (left + right) / 2;

		update(now*2, left, mid, idx, diff);
		update(now*2+1, mid+1, right, idx, diff);

        int r = 0;

        if (segment[now*2] * segment[now*2+1] > 0) r = 1;
        else if (segment[now*2] * segment[now*2+1] < 0) r = -1;

		segment[now] = r;
	}
}

int mul(int now, int left, int right, int start, int end) {
	if (left > end || right < start) return 1;
	if (start <= left && right <= end) return segment[now];

	if (left < right) {
		int mid = (left+right)/2;
		int a = mul(now*2, left, mid, start, end);
		int b = mul(now*2+1, mid+1, right, start, end);

        int r = 0;

        if (a*b > 0) r = 1;
        else if (a*b < 0) r = -1;

		return r;
	}
}

int main() {
    int n, k;

    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            int in;
            scanf("%d", &in);

            update(1, 1, n, i+1, in);
        }

        for (int i = 0; i < k; i++) {
            char c;
            scanf(" %c", &c);
            int x, y;
            scanf("%d%d", &x, &y);

            if (c == 'C') {
                update(1, 1, n, x, y);
            }
            else {
                int r = mul(1, 1, n, x, y);

                if (r > 0) printf("+");
                else if (r < 0) printf("-");
                else printf("0");
            }
        }

        printf("\n");
    }
}