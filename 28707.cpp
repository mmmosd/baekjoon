#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
    int l, r, c;
    vector<int> ary;
} node;

struct cmp {
    bool operator()(node a, node b) {
        return a.c > b.c;
    }
}

int ary[10];
node map[15];
priority_queue<node, vector<node>, cmp> pq;

int n, m;

vector<int> swap(vector<int> ary, int l, int r) {
    vector<int> result = ary;
    int temp = result[l];
    result[l] = result[r];
    result[r] = temp;
    return result;
}

int find() {
    pq.push();
    while (!pq.empty()) {
        node now = pq.top();

        for (int i = 0; i < m; i++) {
            node move = {map[i].l, map[i].r, map[i].c, now.ary};

            if () continue;

            pq.push(move);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        map[i] = {l, r, c};
    }
}