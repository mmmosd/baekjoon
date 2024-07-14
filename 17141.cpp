#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
    int i, j, c;
} pos;

vector<pos> viruses;
pos selected_virus[15];
int visV[15];
int map[55][55];

int result = -1;
int count;

int n, m;

int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int bfs() {
    int cost = 0;
    
    int visited[55][55] = {0,};
    queue<pos> q;

    int area = 0;
    for (int i = 0; i < m; i++) {
        q.push(selected_virus[i]);
        visited[selected_virus[i].i][selected_virus[i].j] = 1;
        area++;
    }

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        if (now.c > cost) cost = now.c;

        for (int i = 0; i < 4; i++) {
            pos move = {now.i + dir[i][0], now.j + dir[i][1], now.c + 1};

            if (move.i >= n || move.j >= n || move.i < 0 || move.j < 0) continue;
            if (visited[move.i][move.j]) continue;
            if (map[move.i][move.j] == 1) continue;

            visited[move.i][move.j] = 1;
            q.push(move);
            area++;
        }
    }

    if (count != area) return -1;
    else return cost;
}

void find(int now, int idx) {
    if (now == m) {
        int time = bfs();
        if ((time < result && time != -1) || result == -1) result = time;
    }
    else if (now < m) {
        int cnt = viruses.size();
        for (int i = idx; i < cnt; i++) {
            if (visV[i] == 1) continue;

            visV[i] = 1;
            selected_virus[now] = viruses[i];
            find(now+1, i);
            visV[i] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 2) {
                viruses.push_back({i, j, 0});
            }

            if (map[i][j] != 1) count++;
        }
    }

    find(0, 0);

    printf("%d", result);
}