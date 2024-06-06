#include <stdio.h>
#include <stack>
using namespace std;

typedef long long ll;

int n;

int main() {
    scanf("%d", &n);

    stack<ll> s;
    ll now_size = 0;
    ll result = 0;

    for (int i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);

        if (s.size() > 0 && temp < s.top()) {
            ll min = s.top(), len = s.size();
            while (!s.empty()) {
                if (s.top() < min) {
                    min = s.top();
                }

                s.pop();
            }

            now_size = min*len;

            if (now_size > result) {
                result = now_size;
            }
        }
        else {
            s.push(temp);
        }
        
        // 현재 top보다 temp가 작다면 => 모두 pop하며, 그 때의 min값과 그 전에 있던 stack의 크기를 곱한 값이 직사각형의 크기가 된다.
        // 아니라면 걍 push ㅇㅇ
    }

    printf("%lld", result);
}