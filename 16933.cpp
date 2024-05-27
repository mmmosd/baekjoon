#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j, chk, cost, day;
} pos;

int map[1005][1005];
int visited[1005][1005][15];
queue<pos> q;

int n, m, k;

int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int main() {
    scanf("%d%d%d", &n, &m, &k);

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

    q.push({0, 0, 0, 1, 1});
    visited[0][0][0] = 1;

    int result = 1987654321;

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            pos move;

            if (i >= 4) {
                move = {now.i + dir[i-4][0], now.j + dir[i-4][1], now.chk, now.cost+2, now.day};
            }
            else {
                move = {now.i + dir[i][0], now.j + dir[i][1], now.chk, now.cost+1, !now.day};
            }

            if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;

            if (move.i == n-1 && move.j == m-1) {
                if (move.cost < result) result = move.cost;
                continue;
            }

            if (move.day == 0) {
                if (map[move.i][move.j] == 1 && move.chk == k) continue;
                if (map[move.i][move.j] == 1) move.chk++;
            }
            else {
                if (map[move.i][move.j] == 1) continue;
            }

            if (visited[move.i][move.j][move.chk] <= move.cost && visited[move.i][move.j][move.chk] > 0) continue;
            visited[move.i][move.j][move.chk] = move.cost;

            q.push(move);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%3d", visited[i][j]-1);
    //     }
    //     puts("");
    // }

    if (result == 1987654321) {
        printf("-1");
    }
    else {
        printf("%d", result);
    }
}