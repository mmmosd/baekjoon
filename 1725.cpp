#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> segment;

int n;

void update(int now, int left, int right, int idx, ll diff) {
    if (left == right) segment[now] = diff;

    if (left < right) {
        int mid = (left + right) / 2;

        update(now*2, left, mid, idx, diff);
        update(now*2+1, mid+1, right, idx, diff);

        segment[now] = segment[now*2] + segment[now*2+1];
    }
}

void sum() {
    
}

int main() {
    scanf("%d", &n);

    segment.resize(n*4);

    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);

        update(1, 1, n, i, t);
    }
}