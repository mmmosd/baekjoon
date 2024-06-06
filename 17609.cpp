#include <stdio.h>
#include <string.h>

int t;

int find(char* str) {
    int start = 0, end = strlen(str)-1;
    int chk1 = 0, chk2 = 0;
    
    while (start <= end) {
        if (chk1 >= 2) break;

        if (str[start] != str[end]) {
            chk1++;
            end--;
            
            if (str[start] != str[end]) {
                chk1++;
                break;
            }
        }
        
        start++;
        end--;
    }

    start = 0, end = strlen(str)-1;

    while (start <= end) {
        if (chk2 >= 2) break;

        if (str[start] != str[end]) {
            chk2++;
            start++;

            if (str[start] != str[end]) {
                chk2++;
                break;
            }
        }
        
        start++;
        end--;
    }

    if (chk1 == 1 || chk2 == 1) return 1;
    if (chk1 == 0 || chk2 == 0) return 0;

    return 2;
}

int main() {
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char str[100005] = {0,};
        scanf(" %s", str);

        printf("%d\n", find(str));
    }
}