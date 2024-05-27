#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j;
} pos;

int map[1005][1005];
int visited[1005][1005];
queue<pos> q;

int n, m;

int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);

            map[i][j] = c - '0';
        }
    }


    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                q.push({i, j});

                int r = 0;

                while (!q.empty()) {
                    pos now = q.front();
                    q.pop();

                    r++;

                    for (int k = 0; k < 4; k++) {
                        pos move = {now.i + dir[k][0], now.j + dir[k][1]};

                        if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
                        if (map[move.i][move.j] != 0) continue;
                        if (visited[move.i][move.j] == num) continue;
                        visited[move.i][move.j] = num;

                        q.push(move);
                    }
                }

                map[i][j] = r;
                num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", map[i][j]);
        }
        puts("");
    }
}