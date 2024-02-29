#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int i, j, t;
} pos;

int map[55][55];

int emptyArea;

vector<pos> all_virus;
pos selected_virus[15];
int virus_visited[15];

int n, m;

int result = -1;

int dir[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int bfs() {
	int visited[55][55] = {0,};
	queue<pos> q;
	
	int virusArea = 0;
	int time = 0;
		
	for (int i = 0; i < m; i++) {
		q.push(selected_virus[i]);
		visited[selected_virus[i].i][selected_virus[i].j] = 1;
	}
	
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		
		if (map[now.i][now.j] == 0) virusArea++;
		time = now.t;
		
		if (virusArea >= emptyArea) return time;
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i + dir[i][0], now.j + dir[i][1], now.t + 1};
			
			if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= n) continue;
			if (visited[move.i][move.j]) continue;
			if (map[move.i][move.j] == 1) continue;
			
			visited[move.i][move.j] = 1;
			q.push(move);
		}
	}
	
//	printf("%d | %d\n", virusArea, emptyArea);
	
	if (virusArea >= emptyArea) return time;
	else return -1;
}

void find(int now, int t) {
	if (now == m) { //bfs
		int time = bfs();
		
		if (time != -1) {
			if (time < result || result == -1) result = time;
		}
		
		return;
	}
	
	int virus_cnt = all_virus.size();
	for (int i = t; i < virus_cnt; i++) {
		if (!virus_visited[i]) {
			virus_visited[i] = 1;
			selected_virus[now] = all_virus[i];
			find(now+1, i);
			virus_visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			
			if (map[i][j] == 2) all_virus.push_back({i, j, 0});
			if (map[i][j] == 0) emptyArea++;
		}
	}
	
	find(0, 0);
	
	printf("%d", result);
}
