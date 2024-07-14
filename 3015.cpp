#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;

int result;

int n;

int main() {
    scanf("%d", &n);

    result = n-1;
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);

        if (s.empty()) {
            s.push(in);
            continue;
        }

        while (!s.empty() && s.top() <= in) {
            s.pop();
            result++;
        }
        
        s.push(in);
    }

    printf("%d", result);
}