#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int i, j;
} pos;

int map[15][15];
int parent[15][15];

int n, m;

int dir[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int find_in_grid(pos p) {
	if (map[p.i][p.j] == find_in_grid(p)) return map[p.i][p.j];
	
	for (int i = 0; i < 4; i++) {
		pos move = {p.i+dir[i][0], p.j+dir[i][1]};
		
		if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
		if (map[move.i][move.j] == 0) continue;
		
		merge_in_grid(now, move);
	}
}

void merge_in_grid(pos a, pos b) {
	int a_root = find_in_grid(a), b_root = find_in_grid(b);
	
	if (a_root == b_root) return;
	
	if (a_root < b_root) {
		map[b.i][b.j] = a_root;
	}
	else {
		map[a.i][a.j] = b_root;
	}
}

void make_island(queue<pos> q) {
	int visited[15][15] = {0,};
	
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			pos move = {now.i+dir[i][0], now.j+dir[i][1]};
			
			if (move.i < 0 || move.j < 0 || move.i >= n || move.j >= m) continue;
			if (visited[move.i][move.j] == 1) continue;
			if (map[move.i][move.j] == 0) continue;
			
			visited[move.i][move.j] = 1;
			merge_in_grid(now, move);
		}
	}
}

int find_in_graph() {
	
}

void merge_in_graph() {
	
}

int main() {
	scanf("%d%d", &n, &m);
	
	queue<pos> q;
	int N = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) q.push({i, j}), map[i][j] = N++;
		}
	}
	
	make_island(q);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	
	//�� ���鸶�� �ֻ��� ��带 ���ϱ� 
	//�� ���鸶�� �ִܰŸ��� ���� ������ ����ġ�� ���ϱ� 
	//�׷��� ���� ����ġ�� ���� �ּ� ���д� Ʈ�� �����
	//�ּ� ���д� Ʈ���� ��� ����ġ ���ϱ�
	
	//���� �����ϴ� ���հ� ���� ���� ������ ���� �����ؾ� ��  
}
