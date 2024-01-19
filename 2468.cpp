#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int i, j;
} pos;

int map[105][105];
int visited[105][105];
int parents[105][105];

struct cmp{
	bool operator()(pos a, pos b) {
		return parents[a.i][a.j] > parents[b.i][b.j];
	}
};

priority_queue<pos, vector<pos>, cmp> q;

int dir[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int n;

int bfs(int rain) {
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 1;
			parents[i][j] = 0;
			if (map[i][j] > rain) {
				visited[i][j] = 0;
				parents[i][j] = num++;
				q.push({i, j});
			}
		}
	}
	
	while (!q.empty()) {
		pos now = q.top();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i + dir[i][0], now.j + dir[i][1]};
			
			if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= n) continue;
			if (visited[move.i][move.j] == 1) continue;
			
			visited[move.i][move.j] = 1;
			parents[move.i][move.j] = parents[now.i][now.j];
			q.push(move);
		}
	}
	
	int pary[105] = {0,};
//	printf("-------------%d\n", rain);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
//			printf("%d ", parents[i][j]);
			
			pary[parents[i][j]] = 1;
		}
//		puts("");
	}
	
	
	int result = 0;
	for (int i = 1; i <= 100; i++) {
		if (pary[i] == 1) result++;
		pary[i] = 0;
	}
	
	return result;
}

int main() {
	scanf("%d", &n);
	
	
	int max = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			
			if (map[i][j] > max) max = map[i][j];
		}
	}
	
	int result = 1;
	for (int i = 0; i <= max; i++) {
		int temp = bfs(i);
		
		if (temp > result) result = temp;
	}
	
	printf("%d", result);
}
