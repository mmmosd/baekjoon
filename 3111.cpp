#include <stdio.h>
#include <string.h>

typedef struct {
    char c;
    int v;
} node;

char T[300005], A[30], result[300005];

node stack[300005];
int point = -1;

void push(char c, int v) {
    stack[++point] = {c, v};
}

void pop() {
    point--;
}

node peek() {
    return stack[point];
}

int main() {
    scanf("%s", A);
    scanf(" %s", T);

    int Tlen = strlen(T), Aend = strlen(A)-1;
    int nowV = 0;

    for (int i = 0; i < Tlen; i++) {
        char now = T[i];

        if (now == A[nowV]) {
            nowV++;
        }
        else {
            nowV = 0;
        }

        push(now, nowV);

        if (nowV == Aend) {
            for (int j = 0; j < Aend+1; j++) {
                pop();
            }

            nowV = peek().v;
            printf(" ! ");
        }

        printf("%c", now);
    }
}