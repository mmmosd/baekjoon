#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct {
    int s, e, t;
} Edge;

int tc;

bool find(int n, int m, int w) {
    vector<Edge> edge;
    ll dist[505] = {0,};

    for (int i = 2; i <= n; i++) {dist[i] = 2000000000;}
    
    for (int i = 0; i < m; i++) { //지점
        int s, e, t;
        // s, e: 노드 | t: 간선 가중치

        scanf("%d%d%d", &s, &e, &t);

        edge.push_back({s, e, t});
        edge.push_back({e, s, t});
    }

    for (int i = 0; i < w; i++) { //웜홀
        int s, e, t;
        // s, e: 노드 | t: 간선 가중치

        scanf("%d%d%d", &s, &e, &t);

        edge.push_back({s, e, -t});
    }

    int edgecnt = edge.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < edgecnt; j++) {
            int s = edge[j].s, e = edge[j].e, t = edge[j].t;

            // if (dist[s] != 2000000000 && dist[s] + t < dist[e]) {
            if (dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;

                if (i == n-1) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        int n, m, w;
        // n: 지점의 수 | m: 도로의 개수 | w: 웜홀의 개수
        scanf("%d%d%d", &n, &m, &w);

        bool result = find(n, m, w);

        if (result) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}