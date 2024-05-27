#include <stdio.h>
#include <stack>
#include <memory.h>
using namespace std;

int result[1000005];
stack<int> s;

int n;

int main() {
    memset(result,-1,sizeof(result));
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int input, top = s.empty()?input+1:s.top();
        scanf("%d", &input);

        if (input > top) {
            int j = i-1;
            while (!s.empty()) {
                int p = s.top();

                if (p >= input) break;

                s.pop();

                result[j] = input;
                j--;
            }
        }

        s.push(input);
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}