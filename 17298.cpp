#include <stdio.h>
#include <stack>
#include <memory.h>
using namespace std;

typedef struct {
    int i, v;
} node;

int result[1000005];
stack<node> s;

int n;

int main() {
    memset(result,-1,sizeof(result));
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);

        int top = s.empty()?input+1:s.top().v;

        if (input > top) {
            while (!s.empty()) {
                node p = s.top();

                if (p.v >= input) break;
                s.pop();

                result[p.i] = input;
            }
        }

        s.push({i, input});
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}