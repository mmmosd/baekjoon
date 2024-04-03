#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int i, j;
} pos;

int map[505][505];
int visited[505][505];
queue<pos> q;

int n, m;

int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int result_count = 0, max_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                result_count++;

                q.push({i, j});

                visited[i][j] = 1;
                map[i][j] = result_count;

                int size = 1;

                while (!q.empty())
                {
                    pos now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        pos move = {now.i + dir[d][0], now.j + dir[d][1]};

                        if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
                        if (map[move.i][move.j] == 0) continue;
                        if (visited[move.i][move.j] == 1) continue;

                        size++;

                        visited[move.i][move.j] = 1;
                        map[move.i][move.j] = result_count;
                        q.push(move);
                    }
                }

                if (size > max_size) max_size = size;
            }
        }
    }
    
    printf("%d\n", result_count);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     puts("");
    // }

    printf("%d", max_size);
}