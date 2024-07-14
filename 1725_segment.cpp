#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
    ll min, idx;
} node;

vector<node> tree;

int n;

void update_tree(int now, int left, int right, int idx, ll diff) {
    if (idx < left || idx > right) return;

    if (left == right) {
        tree[now].min = diff;
        tree[now].idx = idx;
    }

    if (left < right) {
        int mid = (left + right) / 2;

        update_tree(now*2, left, mid, idx, diff);
        update_tree(now*2+1, mid+1, right, idx, diff);

        if (tree[now*2].min < tree[now*2+1].min) tree[now] = tree[now*2];
        else tree[now] = tree[now*2+1];
    }
}

int main() {
    scanf("%d", &n);

    tree.resize(n*4);
    for (int i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);

        update_tree(1, 1, n, i+1, in);
    }

    int idx = tree[1];

    printf("%lld", );
}