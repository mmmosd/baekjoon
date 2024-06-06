#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int n, k, c; // n = 수빈이, k = 동생, c = 현재까지 걸린 시간
} info;

int visited[500005][2];
int n, k;

int dir[2] = {-1, 1};

int find() {
    queue<info> q;

    if (n == k) return 0;

    q.push({n, k, 0});

    while (!q.empty()) {
        info now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            info move = {i<2?now.n+dir[i]:now.n*2, now.k+now.c+1, now.c+1};

            if (move.n < 0 || move.n > 500000 || move.k > 500000) continue;
            if (visited[move.n][move.c%2] != 0) continue;

            visited[move.n][move.c%2] = move.c;

            if (visited[move.k][move.c%2] != 0) {
                if ((move.c - visited[move.k][move.c%2])%2 == 0) {
                    return move.c;
                }
            }
            
            q.push(move);
        }
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &k);

    printf("%d", find());
}