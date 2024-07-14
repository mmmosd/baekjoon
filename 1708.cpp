#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int x, y;
} pos;

pos ary[100005];

pos t;

int n;

int ccw(pos a, pos b, pos c) {
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

bool cmp(pos a, pos b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ary[i].x, &ary[i].y);
    }

    sort(ary, ary+n, cmp);

    pos a, b, c;
    stack<pos> s1;

    s1.push(ary[0]);
    s1.push(ary[1]);
    for (int i = 2; i < n; i++) {
        while (s1.size() >= 2) {
            pos a = s1.top();
            s1.pop();
            pos b = s1.top();
            if (ccw(a, b, ary[i]) > 0){
                s1.push(b);
                break;
            }
        }
        s1.push(ary[i]);
    }

    stack<pos> s2;
    s2.push(ary[0]);
    s2.push(ary[1]);
    for (int i = 2; i < n; i++) {
        while (s2.size() >= 2) {
            pos a = s2.top();
            s2.pop();
            pos b = s2.top();
            if (ccw(a, b, ary[i]) > 0){
                s2.push(b);
                break;
            }
        }
        s2.push(ary[i]);
    }

    printf("%d", s1.size() + s2.size());
}