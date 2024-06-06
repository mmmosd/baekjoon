#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct {
    int count, clip, g;
} Emoji;

int visited[1005][1005];

int s;

int main() {
    scanf("%d", &s);

    memset(visited, -1, sizeof(visited));

    queue<Emoji> q;

    q.push({1, 0, 0});

    while (!q.empty()) {
        Emoji now = q.front();
        q.pop();

        if (now.count < 0 || now.count > 1000 || now.clip > 1000) continue;
        if (now.g >= visited[now.count][now.clip] && visited[now.count][now.clip] != -1) continue;
        visited[now.count][now.clip] = now.g;

        if (now.count == s) {
            printf("%d", now.g);
            return 0;
        }

        q.push({now.count, now.count, now.g+1}); //copy
        if (now.clip > 0) q.push({now.count + now.clip, now.clip, now.g+1}); //paste
        q.push({now.count-1, now.clip, now.g+1}); //remove one
    }
}