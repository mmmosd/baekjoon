#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

ll tree[1010101];

void update(int now, int left, int right, int idx, ll diff) {
    if (idx < left || idx > right) return;

    if (left == right) {
        tree[now] = diff;
    }

    if (left < right) {
        int mid = (left + right) / 2;
        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        ll a = tree[now*2];
        ll b = tree[now*2+1];

        if (a < b) {
            tree[now] = a;
        }
        else {
            tree[now] = b;
        }
    }
}

ll min(int now, int left, int right, int start, int end) {
    if (end < left || right < start) return 1000000005;
    if (start <= left && right <= end) return tree[now];
    
    if (left < right) {
        int mid = (left + right) / 2;

        ll a = min(now*2, left, mid, start, end);
        ll b = min(now*2+1, mid+1, right, start, end);

        if (a < b) {
            return a;
        }
        else {
            return b;
        }
    }
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);

        update(1, 1, n, i, in);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%lld\n", min(1, 1, n, a, b));
    }
}