#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j;
    int fi, fj;
    int cnt;
} pos;

char map[1005][1005];
int visited[1005][1005];
queue<pos> q;

int n, m;

int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    scanf("%d%d", &n, &m);

    pos start = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);

            if (map[i][j] == 'J') {
                start.i = i;
                start.j = j;
            }
            else if (map[i][j] == 'F') {
                start.fi = i;
                start.fj = j;
            }
            else if (map[i][j] == '#') {
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        pos now = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            pos move = {now.i + dir[i][0], now.j + dir[i][1], now.fi + dir[i][0], now.fj + dir[i][1], now.cnt + 1};

            if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
            if (visited[move.i][move.j] == 1) continue;

            if (move.i == 0 || move.j == 0 || move.i == n-1 || move.j == m-1) { //exit
                printf("%d", move.cnt);

                return 0;
            }
            
            q.push(move);
            visited[move.fi][move.fj] = 1;
        }
    }

    printf("IMPOSSIBLE");
}