#include <stdio.h>
#include <string.h>

typedef long long ll;

int main() {
    char str[15];
    scanf(" %s", str);

    ll result = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char s[15];
        int temp = 0;
        int a = 1;
        s[len-1] = str[0];
        for (int j = 0; j < len; j++) {
            if (j < len-1) {
                s[j] = str[j+1];
            }
            temp += (str[j] - '0')*a;
            a*=10;
        }
        strcpy(str, s);
        result+=temp;
    }

    printf("%lld", result);
}