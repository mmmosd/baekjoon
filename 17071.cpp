#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int n, c; // n = 수빈이, c = 현재까지 걸린 시간
} info;

int n, k;

int dir[2] = {-1, 1};

int find() {
    int visited[500005][2] = {0,}; // 0: 짝, 1: 홀
    queue<info> q;

    // if (n == k) return 0;

    q.push({n, 0});

    while (!q.empty()) {
        info now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            info move = {i<2?now.n+dir[i]:now.n*2, now.c+1};

            if (move.n < 0 || move.n > 500000) continue;
            if (visited[move.n][0] != 0 || visited[move.n][1] != 0) continue;

            if (move.c%2 == 0) visited[move.n][0] = move.c;
            else visited[move.n][1] = move.c;

            q.push(move);
        }
    }

    printf("find\n");

    for (int i = 0; k <= 500000; i++) {
        if (visited[i][0] != 0 || visited[i][1] != 0) {
            if (visited[k][0] != 0 && i%2 == 0) return i;
            if (visited[k][1] != 0 && i%2 != 0) return i;
        }

        k += i+1;
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &k);

    printf("%d", find());
}