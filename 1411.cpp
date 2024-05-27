#include <stdio.h>
#include <string.h>

char str[105][55];

int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        gets();
        scanf("%s", str[i]);
    }

    int len = strlen(str[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int cnt = 0;

            for (int k = 0; k < len; k++) {
                if (str[i][j][k] != str[j][i][k]) {

                }
            }
        }
    }
}