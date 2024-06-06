#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef struct {
    int start, end;
} lesson;

bool cmp(lesson a, lesson b) {
    if (a.start != b.start) return a.start < b.start;
    else return a.end < b.end;
}

lesson ary[200005];
priority_queue<int, vector<int>, greater<int>> pq;

int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ary[i].start, &ary[i].end);
    }

    sort(ary, ary+n, cmp);

    int result = 0;

    pq.push(ary[0].end);

    for (int i = 1; i < n; i++) {
        lesson now = ary[i];

        if(now.start >= pq.top()) {
            pq.pop();
        }

        pq.push(now.end);
    }

    result = pq.size();

    printf("%d", result);
}