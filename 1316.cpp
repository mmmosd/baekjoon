#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int result = 0;
    for (int i = 0; i < n; i++) {
        char str[105] = {0,};
        scanf("%s", str);

        int r = 1;
        int len = strlen(str);
        char before = str[0];
        for (int j = 1; j < len; j++) {
            if (before != str[j]) {
                for (int k = 0; k < j; k++) {
                    if (str[k] == str[j]) {
                        r = 0;
                        break;
                    }
                }
            }

            before = str[j];
        }

        result += r;
    }

    printf("%d", result);
}