#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j, chk, cost;
} pos;

int map[1005][1005];
int visited1[1005][1005];
int visited2[1005][1005];
queue<pos> q;

int n, m;

int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    scanf("%d%d", &n, &m);

    if (n == 1 && m == 1) {
        printf("1");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);

            map[i][j] = c - '0';
        }
    }

    q.push({0, 0, 0, 1});

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pos move = {now.i + dir[i][0], now.j + dir[i][1], now.chk, now.cost+1};

            if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
            if (map[move.i][move.j] == 1 && move.chk == 1) continue;
            if (map[move.i][move.j] == 1 && move.chk == 0) move.chk = 1;

            if (move.chk == 0) {
                if (visited1[move.i][move.j] == 1) continue;
                visited1[move.i][move.j] = 1;
            }
            else {
                if (visited2[move.i][move.j] == 1) continue;
                visited2[move.i][move.j] = 1;
            }

            if (move.i == n-1 && move.j == m-1) {
                printf("%d", move.cost);
                return 0;
            }

            q.push(move);
        }
    }

    printf("-1");
}