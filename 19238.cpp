#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _pos{
	int i, j;
	int cost;
} pos;

int map[25][25];
int visited[25][25];
pos T;
queue<pos> q;

int target = -1;

int startP[25][25];
int endP[25][25];

int arrived;

int n, m, f;

int dir[4][2] = {
	{-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

int main() {
	scanf("%d%d%d", &n, &m, &f);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int a, b;
	scanf("%d%d", &a, &b);
	T = {a, b, 0};
	q.push(T);
	
	for (int i = 0; i < m; i++) {
		int s1, s2, e1, e2;
		scanf("%d%d%d%d", &s1, &s2, &e1, &e2);
		
		startP[s1][s2] = i;
		endP[e1][e2] = i;
		
		map[s1][s2] = 2;
		map[e1][e2] = 3;
	}
	
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i + dir[i][0], now.j + dir[i][1], now.cost+1};
			
			if (move.i < 1 || move.j < 1 || move.i >= n+1 || move.j >= n+1) continue;
			if (map[move.i][move.j] == 1) continue;
			if (visited[move.i][move.j] == 1) continue;
			if (f - move.cost < 0) continue;
			
			if (map[move.i][move.j] == 2) { // startP
				if (target == -1) {
					f -= move.cost;
					
					move.cost = 0;
					target = startP[move.i][move.j];
					
					map[move.i][move.j] = 0;
					
					while (!q.empty()) {
						q.pop();
					}
					
					for (int j = 1; j <= n; j++) {
						for (int k = 1; k <= n; k++) {
							visited[j][k] = 0;
						}
					}
					
					q.push(move);
					visited[move.i][move.j] = 1;
//					printf("startP: %d, f: %d\n", target, f);
					
					break;
				}
			}
			
			if (target != -1 && map[move.i][move.j] == 3) { // endP
				if (target == endP[move.i][move.j]) { // arrived
					f += move.cost;
					arrived += 1;
					
					move.cost = 0;
					target = -1;
					
					map[move.i][move.j] = 5;
					
//					printf("-------------%d\n", f);
//					
//					for (int j = 1; j <= n; j++) {
//						for (int k = 1; k <= n; k++) {
//							printf("%3d", map[j][k]);
//						}
//						puts("");
//					}
					
					map[move.i][move.j] = 0;
					
					while (!q.empty()) {
						q.pop();
					}
					
					for (int j = 1; j <= n; j++) {
						for (int k = 1; k <= n; k++) {
							visited[j][k] = 0;
						}
					}
					
					if (arrived < m) {
						q.push(move);
						visited[move.i][move.j] = 1;
					}
					
					break;
				}
				
				continue;
			}
			
			q.push(move);
			visited[move.i][move.j] = 1;
		}
	}
	
	if (arrived < m) {
		printf("-1");
	}
	else {
		printf("%d", f);
	}
}
