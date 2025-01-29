#include <stdio.h>
#include <stack>
using namespace std;

typedef long long ll;

typedef struct {
    ll v, scnt;
} hum;

stack<hum> s;

ll result;

ll n;

int main() {
    scanf("%lld", &n);

    for (ll i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);

        ll max = 0;
        while (!s.empty() && s.top().v < temp) {
            if (max <= s.top().v) {
                max = s.top().v;
                result+=s.top().scnt+1;
            }
            
            s.pop();
        }

        ll scnt = 0;
        while (!s.empty() && s.top().v == temp) {
            scnt+=s.top().scnt+1;
            s.pop();
        }

        result += scnt;

        if (!s.empty()) result++;

        s.push({temp, scnt});
    }
    
    printf("%lld", result);
}