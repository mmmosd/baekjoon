#include <stdio.h>
#include <deque>
using namespace std;

int ary[5000005];
deque<int> dq;

int n, l;

int main() {
    scanf("%d%d", &n, &l);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && ary[dq.back()] >= ary[i]) {
            dq.pop_back();
        }

        while (!dq.empty() && dq.front() < i - l + 1) {
            dq.pop_front();
        }

        dq.push_back(i);
        printf("%d ", ary[dq.front()]);
    }
}