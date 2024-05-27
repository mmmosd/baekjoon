#include <stdio.h>
#include <string.h>


int main() {
    char str[1000005] = {0,};
    scanf("%s", str);

    int len = strlen(str);
    int zcount = 0, ocount = 0;

    if (str[0] == '0') zcount = 1;
    else ocount = 1;

    for (int i = 1; i < len; i++) {
        if (str[i-1] != str[i]) {
            if (str[i] == '0') zcount++;
            else ocount++;
        }
    }

    // printf("%d %d\n", zcount, ocount);

    if (zcount < ocount) printf("%d", zcount);
    else printf("%d", ocount);
}