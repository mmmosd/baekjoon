#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j;
} pos;

int map[105][105]; // cheeze = 1, air = 2

int n, m;

int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

void air_update() {
    int visited[105][105] = {0,};
    queue<pos> q;

    q.push({0, 0});
    map[0][0] = 2;
    visited[0][0] = 1;

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            pos move = {now.i + dir[i][0], now.j + dir[i][1]};

            if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
            if (visited[move.i][move.j] == 1) continue;
            if (map[move.i][move.j] == 1) continue;

            visited[move.i][move.j] = 1;
            map[move.i][move.j] = 2;
            q.push(move);
        }
    }
}

bool cheeze_update() {
    int visited[105][105] = {0,};
    bool cheeze = false;

    // puts("================================================================");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int aircnt = 0;

                for (int k = 0; k < 4; k++) {
                    pos now = {i + dir[k][0], j + dir[k][1]};

                    if (now.i < 0 || now.j < 0 || now.i >= n || now.j >= m) continue;
                    if (visited[now.i][now.j] == 0 && map[now.i][now.j] == 2) aircnt++;

                    if (aircnt >= 2) {
                        visited[i][j] = 1;
                        map[i][j] = 2;
                        break;
                    }
                }

                // printf("%d ", aircnt);

                cheeze = true;
            }
            // else printf("%d ", 0);
        }
        // puts("");
    }

    return cheeze;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int result = 0;
    while (true) {
        air_update();
        bool b = cheeze_update();

        if (b == false) break;
        result++;

        // puts("================================================================");
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         printf("%d ", map[i][j]);
        //     }
        //     puts("");
        // }
    }

    printf("%d", result);
}