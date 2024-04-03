#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
	int i, j;
} pos;

int map[105][105];
int visited[105][105];
int parents[105][105];

queue<pos> q;

int dir[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int n;

int bfs(int rain) {
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			if (map[i][j] > rain) {
				visited[i][j] = 1;
				parents[i][j] = num++;
				q.push({i, j});
				
				while (!q.empty()) {
					pos now = q.front();
					q.pop();
					
					for (int i = 0; i < 4; i++) {
						pos move = {now.i + dir[i][0], now.j + dir[i][1]};
						
						if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= n) continue;
						if (visited[move.i][move.j] == 1) continue;
						if (map[move.i][move.j] <= rain) continue;
						
						visited[move.i][move.j] = 1;
						parents[move.i][move.j] = parents[now.i][now.j];
						q.push(move);
					}
				}
			}
		}
	}
	
//	printf("-------------%d\n", rain);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
//			printf("%d ", parents[i][j]);
			visited[i][j] = 0;
			parents[i][j] = 0;
		}
//		puts("");
	}
	
	int result = num-1;
//	printf("%d\n", result);
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int result = 0;
	for (int i = 0; i <= 101; i++) {
		int temp = bfs(i);
		
		if (temp > result) result = temp;
	}
	
	printf("%d", result);
}
