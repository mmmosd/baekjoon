#include <stdio.h>

int vis[20005];
char str[20005];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str);

    int result = 0;
    for (int i = 0; i < n; i++) {
        char now = str[i];

        for (int j = -k; j <= k; j++) {
            if (i+j < 0 || i+j >= n) continue;

            if (now == 'P' && str[i+j] == 'H' && vis[i+j] == 0) {
                vis[i+j] = 1;
                result++;
                break;
            }
        }
    }

    printf("%d", result);
}