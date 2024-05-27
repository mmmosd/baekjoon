#include <stdio.h>
#include <string.h>
int main() {
    double s1 = 0, s2 = 0;
    for (int i = 0; i < 20; i++) {
        char sub[55], grade[5];
        double n, t = 0;
        scanf("%s %lf %s", sub, &n, grade);

        if (strcmp(grade, "P") == 0) continue;

        if (strcmp(grade, "A+") == 0) {
            t = 4.5;
        }
        else if (strcmp(grade, "A0") == 0) {
            t = 4.0;
        }
        else if (strcmp(grade, "B+") == 0) {
            t = 3.5;
        }
        else if (strcmp(grade, "B0") == 0) {
            t = 3.0;
        }
        else if (strcmp(grade, "C+") == 0) {
            t = 2.5;
        }
        else if (strcmp(grade, "C0") == 0) {
            t = 2.0;
        }
        else if (strcmp(grade, "D+") == 0) {
            t = 1.5;
        }
        else if (strcmp(grade, "D0") == 0) {
            t = 1.0;
        }

        s1 += t*n;
        s2 += n;
    }

    printf("%.6f", s1/s2);
}