#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _pos{
	int i, j;
	int cost;
} pos;

int map[25][25];
int visited[25][25];
int endIdx[25][25];
pos endP[500];
queue<pos> q;

int target = -1;

int arrived;

int n, m, f;

int dir[4][2] = {
	{-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

int main() {
	scanf("%d%d%d", &n, &m, &f);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int a, b;
	scanf("%d%d", &a, &b);
	q.push({a, b, f});
	
	for (int i = 0; i < m; i++) {
		int s1, s2, e1, e2;
		scanf("%d%d%d%d", &s1, &s2, &e1, &e2);
		
		map[s1][s2] = 2; //start
		map[e1][e2] = 3; //end
		
		endIdx[s1][s2] = i;
		endP[i] = {e1, e2, 0};
	}
	
	pos startP = {25, 25, 500005};
	int start_num = -1;
	
	while (!q.empty()) { // find startP
		pos now = q.front();
		q.pop();
		
		if (visited[now.i][now.j]) continue;
		if (map[now.i][now.j] == 1) continue;
		if (now.cost < 0) continue;
		
		visited[now.i][now.j] = 1;
		
		if (map[now.i][now.j] == 2) {
			puts("found!");
			if (now.cost == startP.cost) {
				if (now.i == startP.i) {
					if (now.j == startP.j) {
						//same
					}
					else if (now.j < startP.j) {
						startP = now;
						start_num = endIdx[now.i][now.j];
					}
				}
				else if (now.i < startP.j) {
					startP = now;
					start_num = endIdx[now.i][now.j];
				}
			}
			else if (now.cost < startP.cost) {
				startP = now;
				start_num = endIdx[now.i][now.j];
			}
		}
		
//		map[now.i][now.j] = 8;
//		puts("===================");
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%2d", visited[i][j]);
//			}
//			puts("");
//		}
//		puts("===================");
//		map[now.i][now.j] = 0;
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i + dir[i][0], now.j + dir[i][1], now.cost-1};
			
			if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= n) continue;
			
			q.push(move);
		}
	}
	
	printf("%d: (%d, %d)\n", start_num, endP[start_num].i, endP[start_num].j);
	
	q.push(startP);
	
	while (!q.empty()) {
		
	}
	
	if (arrived < m) {
		printf("-1");
	}
	else {
		printf("%d", f);
	}
}
