#include <stdio.h>
#include <stack>
using namespace std;

typedef long long ll;

typedef struct {
    ll height, idx;
} stick;

int n;

int main() {
    scanf("%d", &n);

    stack<stick> s;
    ll result = 0;

    int i;
    for (i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);

        if (s.size() > 0 && in < s.top().height) {
            ll size = 0;
            while (!s.empty()) {
                stick now = s.top();

                if (now.height <= in) break;
                s.pop();

                if (size < now.height*(i-now.idx)) size = now.height*(i-now.idx);
                printf("==%d\n", now.height*(i-now.idx));
            }

            if (size > result) result = size;
        }


        s.push({in, i});
    }

    ll size = 0;
    while (!s.empty()) {
        stick now = s.top();
        s.pop();

        if (size < now.height*(i-now.idx)) size = now.height*(i-now.idx);

        printf("==%d\n", now.height*(i-now.idx));
    }

    if (size > result) result = size;

    printf("%lld", result);
}