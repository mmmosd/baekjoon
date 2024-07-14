#include <stdio.h>
#include <stack>
#include <memory.h>
using namespace std;

typedef long long ll;

typedef struct {
    ll v, i;
} T;

int main() {
    ll n;
    scanf("%d", &n);

    ll ary[80005] = {0,};
    ll rary[80005] = {0,};

    memset(rary, -1, sizeof(rary));

    stack<T> s;
    ll result = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        if (s.size() > 0 && ary[i] >= s.top().v) {
            T tmp = {-1, -1};
            while (!s.empty()) {
                if (s.top().v >= ary[i]) {
                    tmp = s.top();
                    break;
                }

                s.pop();
            }

            if (tmp.v != -1 && tmp.i != -1) {
                rary[i] = tmp.i;
            }
            else {
                rary[i] = n;
            }
        }

        s.push({ary[i], i});
    }

    for (int i = 0; i < n; i++) {
        if (rary[i] != -1) {
            result += rary[i]-i-1;
        }
    }
    // puts("");
    // for (int i = 0; i < n; i++) {    
    //     printf("%3d ", i);
    // }
    // puts("");

    printf("%lld", result);
}