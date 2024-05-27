#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int t;

int main() {
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++) {
        vector<int> result;
        int ary[10005] = {0,};
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ary[i]);
        }

        sort(ary, ary+n, cmp);

        for (int i = 0; i < n; i+=2) {
            result.push_back(ary[i]);
        }

        int t = n-1;

        if (t%2 == 0) t--;
        for (int i = t; i >= 0; i -= 2) {
            result.push_back(ary[i]);
        }

        // for (int i = 0; i < n; i++) {
        //     printf("%d ", result[i]);
        // }
        // puts("");

        int rgap = 0, gap;

        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                gap = result[i] - result[0];
                if (gap < 0) gap *= -1;

                if (rgap < gap) rgap = gap;
            }
            else {
                gap = result[i] - result[i+1];
                if (gap < 0) gap *= -1;

                if (rgap < gap) rgap = gap;
            }
        }

        printf("%d\n", rgap);
    }
}