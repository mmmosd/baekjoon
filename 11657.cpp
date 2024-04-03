#include <stdio.h>

typedef long long ll;

typedef struct {
    int a, b, c;
} Edge;

Edge edge[6005];
ll dist[505];

int n, m;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
    
        edge[i] = {a, b, c};
    }

    for (int i = 2; i <= n; i++) {dist[i] = 2000000000;}

    for (int t = 0; t < n; t++) {
        for (int i = 0; i < m; i++) {
            Edge e = edge[i];

            if (dist[e.a] != 2000000000 && dist[e.b] > dist[e.a] + e.c) {
                dist[e.b] = dist[e.a] + e.c;

                if (t == n-1) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == 2000000000) {
            printf("-1\n");
        }
        else {
            printf("%lld\n", dist[i]);
        }
    }
}